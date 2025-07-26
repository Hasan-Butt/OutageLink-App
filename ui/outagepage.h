#ifndef OUTAGEPAGE_H
#define OUTAGEPAGE_H

#include <QWidget>
#include "filemanager.h"
#include "data.h"
namespace Ui {
class OutagePage;
}

class OutagePage : public QWidget
{
    Q_OBJECT

public:
    explicit OutagePage(QWidget *parent = nullptr);
    ~OutagePage();
    void setContext(const QString &username,
                    fileManager &fm,
                    Report      *reports,
                    int         *reportCount);
private slots:
    void on_btnSubmit_clicked();
signals:
    void reportSubmitted(const Report& rpt);
private:
    Ui::OutagePage *ui;
    QString         m_currentUser;
    fileManager    *m_fileManager = nullptr;
    Report         *m_reports     = nullptr;
    int            *m_reportCount = nullptr;
};

#endif // OUTAGEPAGE_H
