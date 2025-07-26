#ifndef REQUESTPAGE_H
#define REQUESTPAGE_H

#include <QWidget>
#include "data.h"
#include "filemanager.h"
namespace Ui {
class RequestPage;
}

class RequestPage : public QWidget
{
    Q_OBJECT

public:
    explicit RequestPage(QWidget *parent = nullptr);
    ~RequestPage();
    void setContext(const QString& currentUser,
                                 fileManager& fm,
                                 Request* requests,
                    int* requestCount);
    void displayRequests();

private slots:

    void handleDeleteRequest();

    void on_btnSubmit_clicked();
signals:
    void requestSubmitted(const Request& req);

private:
    Ui::RequestPage *ui;
    QString         m_currentUser;
    fileManager*    m_fileManager   = nullptr;
    Request*        m_requests      = nullptr;
    int*            m_requestCount  = nullptr;

    void clearTable();

};

#endif // REQUESTPAGE_H
