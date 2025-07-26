#ifndef FEEDPAGE_H
#define FEEDPAGE_H

#include <QWidget>
#include "data.h"
#include "filemanager.h"
namespace Ui {
class FeedPage;
}

class FeedPage : public QWidget
{
    Q_OBJECT

public:
    explicit FeedPage(QWidget *parent = nullptr);
    ~FeedPage();

    void displayReports(Report* reports, int count, const QString& currentUser, fileManager& fm);

signals:
    void editRequested(int index);
    void deleteRequested(int index);

private slots:
    void on_editBtn_clicked();

    void on_deleteBtn_clicked();

    void on_comboFilter_currentTextChanged(const QString &arg1);

private:
    Ui::FeedPage *ui;
    Report* m_reports;
    int m_count;
    QString m_currentUser;
    fileManager* m_fileManager;
    QString      m_filterType = "All";
    QWidget* createReportCard(int index);
    void clearFeed();
};

#endif // FEEDPAGE_H
