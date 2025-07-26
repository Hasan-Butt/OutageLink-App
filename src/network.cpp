#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QList>
#include <QJsonObject>
#include "network.h"

NetworkClient::NetworkClient(const QString& baseUrl, QObject* parent)
    : QObject(parent)
    , m_baseUrl(baseUrl)
{}

//————— FETCH —————
void NetworkClient::fetchReports() {
    auto* reply = mgr.get(QNetworkRequest(QUrl(m_baseUrl + "/api/reports")));
    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleFetchReply<Report>(reply,
                                 [](auto& obj){
                                     Report r;
                                     r.type        = obj["type"].toString();
                                     r.area        = obj["area"].toString();
                                     r.message     = obj["message"].toString();
                                     r.hour        = obj["hour"].toInt();
                                     r.minute      = obj["minute"].toInt();
                                     r.day         = obj["day"].toInt();
                                     r.month       = obj["month"].toInt();
                                     r.year        = obj["year"].toInt();
                                     r.submittedBy = obj["submittedBy"].toString();
                                     return r;
                                 },
                                 [=](auto v){ emit reportsFetched(v); });
    });
}

void NetworkClient::fetchResources() {
    auto* reply = mgr.get(QNetworkRequest(QUrl(m_baseUrl + "/api/resources")));
    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleFetchReply<Resource>(reply,
                                   [](auto& obj){
                                       Resource r;
                                       r.item         = obj["item"].toString();
                                       r.owner        = obj["owner"].toString();
                                       r.availability = obj["availability"].toString();
                                       // if you have isAssigned/assignedTo/dueDateTime fields, map them here
                                       return r;
                                   },
                                   [=](auto v){ emit resourcesFetched(v); });
    });
}

void NetworkClient::fetchRequests() {
    auto* reply = mgr.get(QNetworkRequest(QUrl(m_baseUrl + "/api/requests")));
    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleFetchReply<Request>(reply,
                                  [](auto& obj){
                                      Request r;
                                      r.request  = obj["request"].toString();
                                      r.name     = obj["name"].toString();
                                      r.location = obj["location"].toString();
                                      return r;
                                  },
                                  [=](auto v){ emit requestsFetched(v); });
    });
}

void NetworkClient::fetchAnnouncements() {
    auto* reply = mgr.get(QNetworkRequest(QUrl(m_baseUrl + "/api/announcements")));
    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleFetchReply<Announcement>(reply,
                                       [](auto& obj){
                                           Announcement a;
                                           a.text      = obj["text"].toString();
                                           a.timestamp = QDateTime::fromString(obj["timestamp"].toString(), Qt::ISODate);
                                           a.postedBy  = obj["postedBy"].toString();
                                           return a;
                                       },
                                       [=](auto v){ emit announcementsFetched(v); });
    });
}

//————— POST —————
void NetworkClient::postReport(const Report& r) {
    postItem<Report>("reports", r, [&](){
        QJsonObject o;
        o["type"]        = r.type;
        o["area"]        = r.area;
        o["message"]     = r.message;
        o["hour"]        = r.hour;
        o["minute"]      = r.minute;
        o["day"]         = r.day;
        o["month"]       = r.month;
        o["year"]        = r.year;
        o["submittedBy"] = r.submittedBy;
        return o;
    });
}

void NetworkClient::postResource(const Resource& r) {
    postItem<Resource>("resources", r, [&](){
        QJsonObject o;
        o["item"]         = r.item;
        o["owner"]        = r.owner;
        o["availability"] = r.availability;
        // map isAssigned, assignedTo, dueDateTime if used
        return o;
    });
}

void NetworkClient::postRequest(const Request& r) {
    postItem<Request>("requests", r, [&](){
        QJsonObject o;
        o["request"]  = r.request;
        o["name"]     = r.name;
        o["location"] = r.location;
        return o;
    });
}

void NetworkClient::postAnnouncement(const Announcement& a) {
    postItem<Announcement>("announcements", a, [&](){
        QJsonObject o;
        o["text"]      = a.text;
        o["timestamp"] = a.timestamp.toString(Qt::ISODate);
        o["postedBy"]  = a.postedBy;
        return o;
    });
}


