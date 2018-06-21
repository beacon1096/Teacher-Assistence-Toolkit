#ifndef TATABOUTINTERFACE_H
#define TATABOUTINTERFACE_H

#include <QMainWindow>
#include "BeaconQtAboutData.h"

namespace Ui {
class AboutInterface;
}

class AboutInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutInterface(QWidget *parent = 0);
    ~AboutInterface();
    BeaconAboutData data;
    int authorsCnt;
    int creditsCnt;
    void init();
    void initData();
    void initInterface();
    QString titleFont();
    void addAuthor(QString name,QString job,QString emailAddress,QString homePage,QString IM);
    void addCredit(QString name,QString job,QString emailAddress,QString homePage,QString IM);
    void setupAbout();
    void setupLibraries();
    QString AboutContent();
    void ApplyFont(QFont &Target);
    void setupAuthors();
private slots:
    void closeButtonClicked();
    void SeekURL(QString target);
    void showToolTip(QString target);
private:
    Ui::AboutInterface *ui;
};
#endif // TATABOUTINTERFACE_H
