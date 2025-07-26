#include "filemanager.h"
#include "encryption.h"
#include "encryption.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QMessageBox>
#include <QWidget>

static const QString REPORTS_PATH =
    QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
    + "/OutageReports.txt";
static const QString RESOURCES_PATH =
    QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
    + "/Resources.txt";
static const QString REQUESTS_PATH =
    QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
    + "/Requests.txt";
static const QString ANNOUNCE_PATH =
    QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
    + "/Announcements.txt";

// Ensure dir + file exist
static void ensureFileExists(const QString& path) {
    QFileInfo fi(path);
    QDir().mkpath(fi.path());
    if (!fi.exists()) {
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}
fileManager::fileManager() {}
void fileManager::loadReports(Report reports[], int& size, const char* key) {
        ensureFileExists(REPORTS_PATH);

        QFile file(REPORTS_PATH);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(nullptr, "Load Reports",
                                 "Could not open reports file for reading.");
            size = 0;
            return;
        }

        QTextStream in(&file);
        QRegularExpression dtRe(R"((\d{1,2})-(\d{1,2})-(\d{4})\s+(\d{1,2}):(\d{1,2}))");
        encryption enc;
        size = 0;

        while (!in.atEnd()) {
            if (size >= /* your max capacity, e.g. */ 10) break;

            QString cipher = in.readLine().trimmed();
            if (cipher.isEmpty()) continue;

            QString line = enc.decryptString(cipher, key);
            QStringList parts = line.split('|');
            if (parts.size() != 5) continue;
            reports[size].type        = parts[0];
            reports[size].area        = parts[1];
            reports[size].message     = parts[2];


            if (auto m = dtRe.match(parts[3]); m.hasMatch()) {
                reports[size].day    = m.captured(1).toInt();
                reports[size].month  = m.captured(2).toInt();
                reports[size].year   = m.captured(3).toInt();
                reports[size].hour   = m.captured(4).toInt();
                reports[size].minute = m.captured(5).toInt();
            }
            reports[size].submittedBy = parts[4];

            ++size;
        }

        file.close();
}

void fileManager::saveReports(const Report* arr, int size, const char* key) {

    ensureFileExists(REPORTS_PATH);

    QFile file(REPORTS_PATH);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Save Reports",
                             "Could not open reports file for writing.");
        return;
    }

    QTextStream out(&file);
    encryption enc;
    for (int i = 0; i < size; ++i) {
        QString line = QString("%1|%2|%3|%4-%5-%6 %7:%8|%9")
        .arg(arr[i].type)
            .arg(arr[i].area)
            .arg(arr[i].message)
            .arg(arr[i].day,    2,10,QChar('0'))
            .arg(arr[i].month,  2,10,QChar('0'))
            .arg(arr[i].year)
            .arg(arr[i].hour,   2,10,QChar('0'))
            .arg(arr[i].minute, 2,10,QChar('0'))
            .arg(arr[i].submittedBy);

        QString cipher = enc.encryptString(line, key);
        out << cipher << "\n";
    }
}

void fileManager::loadResources(Resource* resources, int& count, const char* /*key*/) {
    ensureFileExists(RESOURCES_PATH);
    QFile file(RESOURCES_PATH);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        count = 0;
        return;
    }
    QTextStream in(&file);
    count = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        auto parts = line.split('|');
        if (parts.size() != 6) continue;
        resources[count].item         = parts[0];
        resources[count].owner        = parts[1];
        resources[count].availability = parts[2];
        resources[count].isAssigned   = (parts[3] == "1");
        resources[count].assignedTo   = parts[4];
        resources[count].dueDateTime  = QDateTime::fromString(parts[5], Qt::ISODate);
        ++count;
    }
}

void fileManager::saveResources(const Resource* resources, int count, const char* /*key*/) {
    ensureFileExists(RESOURCES_PATH);

    QFile file(RESOURCES_PATH);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&file);
    for (int i = 0; i < count; ++i) {
        out << resources[i].item         << '|'
            << resources[i].owner        << '|'
            << resources[i].availability << '|'
            << (resources[i].isAssigned ? "1" : "0") << '|'
            << resources[i].assignedTo   << '|'
            << resources[i].dueDateTime.toString(Qt::ISODate)
            << "\n";
    }
    file.close();
}

void fileManager::loadRequests(Request requests[], int& count) {
    ensureFileExists(REQUESTS_PATH);
    QFile file(REQUESTS_PATH);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        count = 0;
        return;
    }
    QTextStream in(&file);
    count = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split('|');
        if (parts.size() != 3) continue;
        requests[count].request  = parts[0];
        requests[count].name     = parts[1];
        requests[count].location = parts[2];
        ++count;
    }
    file.close();
}

// >>> saveRequests:
void fileManager::saveRequests(const Request requests[], int count) {
    ensureFileExists(REQUESTS_PATH);
    QFile file(REQUESTS_PATH);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Save Requests",
                             "Could not open requests file for writing.");
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < count; ++i) {
        out << requests[i].request  << '|'
            << requests[i].name     << '|'
            << requests[i].location
            << "\n";
    }
    file.close();
}
void fileManager::loadAnnouncements(Announcement an[], int &count) {
    ensureFileExists(ANNOUNCE_PATH);
    QFile f(ANNOUNCE_PATH);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) { count=0; return; }
    QTextStream in(&f);
    count = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        // Format: ISODate|postedBy|text
        auto parts = line.split('|');
        if (parts.size() < 3) continue;
        an[count].timestamp = QDateTime::fromString(parts[0], Qt::ISODate);
        an[count].postedBy  = parts[1];
        an[count].text      = parts.mid(2).join('|');
        ++count;
    }
}
void fileManager::saveAnnouncements(const Announcement an[], int count) {
    ensureFileExists(ANNOUNCE_PATH);
    QFile f(ANNOUNCE_PATH);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&f);
    for (int i = 0; i < count; ++i) {
        // Make a mutable copy of the text so we can replace newlines
        QString cleanText = an[i].text;
        cleanText.replace('\n', ' ');
        out << an[i].timestamp.toString(Qt::ISODate) << '|'
            << an[i].postedBy << '|'
            << cleanText
            << "\n";
    }
    f.close();
}
