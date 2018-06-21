#include "TATAboutInterfaceKDE.h"
#include "BeaconQtPlatformInfo.h"
#include <KAboutData>
#include <KAboutApplicationDialog>
#include <QObject>
#include <QDebug>
#include <QAction>
#include <QDateTime>
#include <QPixmap>
TATAboutData aboutData;
void TATAboutData::init(){
    static const QDate buildDate = QLocale( QLocale::English ).toDate( QString( __DATE__ ).replace( "  ", " 0" ), "MMM dd yyyy");
    static const QTime buildTime = QTime::fromString( __TIME__, "hh:mm:ss" );
    this->data.setComponentName(this->adTrans.tr("TAT alpha"));
    this->data.setDisplayName(this->adTrans.tr("TAT alpha"));
    this->data.setVersion("alpha 1.0 PR1");
    this->data.setShortDescription(this->adTrans.tr("A Toolkit aimed to help teachers finish boring jobs easily and seemlessly."));
    this->data.setLicense(KAboutLicense::LGPL_V3);
    this->data.setCopyrightStatement(this->adTrans.tr("(c)2017-2018 Beacon Qt DevGrp"));
    this->data.setHomepage("http://www.codeaha.com/");
    this->data.setBugAddress("Beacon1096@outlook.com");
    this->data.setOcsProvider("https://github.com/");
    this->data.addAuthor("Beacon1096",this->adTrans.tr("Programming, Core Processing Backend"),"Beacon1096@outlook.com","http://www.codeaha.com/","@Beacon1096");
    this->data.addAuthor("Polaris1087",this->adTrans.tr("UI Frontend,Translation"),"Polaris1087@outlook.com","http://www.codeaha.com/","");
    this->data.addCredit("Polaris1087",this->adTrans.tr("Encouraging me to finish this project"),"","","");
    this->data.addCredit(this->adTrans.tr("Wuhan Education Bureau"),this->adTrans.tr("I pretty much have nothing to complain about this"),"","http://www.whjyj.gov.cn/","");
    this->data.setProgramLogo(QPixmap(":/pics/resources/pics/Beacon.png"));
    QString versionOutput;
    versionOutput.append(QString("%1\n").arg(version.version));
    versionOutput.append(QString("%1%2\n").arg(this->adTrans.tr("Build date:")).arg(buildDate.toString()));
    versionOutput.append(QString("%1%2\n").arg(this->adTrans.tr("Build time:")).arg(buildTime.toString()));
    this->data.setOtherText(versionOutput);

}
void TATAboutData::show(){
    qDebug() << "[TATADKDE]show";
    KAboutApplicationDialog aboutDialog(aboutData.data,NULL);
    aboutDialog.exec();
}
