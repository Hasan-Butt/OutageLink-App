#ifndef RESOURCEPAGE_H
#define RESOURCEPAGE_H

#include <QWidget>
#include "data.h"
#include "filemanager.h"
namespace Ui {
class ResourcePage;
}

class ResourcePage : public QWidget
{
    Q_OBJECT

public:
    explicit ResourcePage(QWidget *parent = nullptr);
    ~ResourcePage();
    void setContext(const QString& currentUser,
                    fileManager& fm,
                    Resource* resources,
                    int* resourceCount);
    void displayResources();

private slots:
    void on_btnSubmit_clicked();
    void handleAssignReturn();
    void handleDelete();
signals:
    void resourceSubmitted(const Resource& res);

private:
    Ui::ResourcePage *ui;
    QString          m_currentUser;
    fileManager*     m_fileManager   = nullptr;
    Resource*        m_resources     = nullptr;
    int*             m_resourceCount = nullptr;

    void clearTable();

};

#endif // RESOURCEPAGE_H
