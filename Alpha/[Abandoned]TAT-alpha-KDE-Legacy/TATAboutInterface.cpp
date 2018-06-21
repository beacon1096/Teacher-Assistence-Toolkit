#include "TATAboutInterface.h"
#include "ui_TATAboutInterface.h"
#include "BeaconQtPlatformInfo.h"
#include "BeaconQtFontLib.h"
#include <QtCore>
#include <QLabel>
#include <QSizePolicy>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
AboutInterface::AboutInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutInterface)
{
    ui->setupUi(this);
    connect(this->ui->CloseButton,SIGNAL(clicked()),this,SLOT(closeButtonClicked()));
    init();
}

AboutInterface::~AboutInterface()
{
    delete ui;
}
void AboutInterface::initData(){
    authorsCnt=0;
    this->data.setComponentName(tr("TAT alpha"));
    this->data.setDisplayName(tr("TAT alpha"));
    this->data.setVersion("alpha 1.0 PR1");
    this->data.setLicense("LGPL_V3");
    this->data.setShortDescription(tr("A Toolkit aimed to help teachers finish boring jobs easily and seemlessly."));
    //this->data.setLicense(KAboutLicense::LGPL_V3);
    this->data.setCopyrightStatement(tr("(c)2017-2018 Beacon Qt DevGrp"));
    this->data.setHomepage("http://www.codeaha.com/");
    this->data.setBugAddress("Beacon1096@outlook.com");
    this->data.setOcsProvider("https://github.com/");
    //this->data.addCredit("Polaris1087",tr("Encouraging me to finish this project"),"","","");
    //this->data.addCredit(tr("Wuhan Education Bureau"),tr("I pretty much have nothing to complain about this"),"","http://www.whjyj.gov.cn/","");
    this->data.setProgramLogo(QString(":/pics/resources/pics/Beacon.png"));
    data.buildDate = QLocale( QLocale::English ).toDate( QString( __DATE__ ).replace( "  ", " 0" ), "MMM dd yyyy");
    data.buildTime = QTime::fromString( __TIME__, "hh:mm:ss" );
    QString versionOutput;
    versionOutput.append(QString("%1\n").arg(version.version));
    versionOutput.append(QString("%1%2\n").arg(tr("Build date:")).arg(data.buildDate.toString()));
    versionOutput.append(QString("%1%2").arg(tr("Build time:")).arg(data.buildTime.toString()));
    this->data.setOtherText(versionOutput);
}
void AboutInterface::initInterface(){
    this->ui->LogoLabel->setPixmap(QPixmap(this->data.programLogo));
    setupAbout();
    setupAuthors();
    setupLibraries();
}
void AboutInterface::init(){
    initData();
    initInterface();
}
void AboutInterface::setupAbout(){
    this->ui->AboutDisplay->clear();
    this->ui->AboutDisplay->insertPlainText(QString("%1\n\n").arg(data.shortDescription));
    this->ui->AboutDisplay->insertPlainText(QString("%1\n\n").arg(data.otherText));
    this->ui->AboutDisplay->insertPlainText(QString("%1\n\n").arg(data.copyrightStatement));
    this->ui->AboutDisplay->insertHtml(QString("<a href=\"%1\">").arg(data.homepage).append("Visit Homepage:").append(data.homepage).append("</a><br>"));
    this->ui->AboutDisplay->insertPlainText(QString("%1\n\n").arg(data.license));
}
void AboutInterface::setupLibraries(){
    QString headers="         ⡢";QString space=" ";
    QVersionNumber QtVersion=QLibraryInfo::version();
    this->ui->LibrariesDisplay->clear();
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertPlainText(QString(tr("Beacon Qt Library")).append(space).append(version.BeaconLibVersion).append(space));
    this->ui->LibrariesDisplay->insertHtml(QString(" (<i>").append(version.BeaconLibCodeName).append("</i>)"));
    this->ui->LibrariesDisplay->insertPlainText("\n");
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertPlainText(QString(tr("Qt Runtime")).append(space).append(QtVersion.toString()).append("\n"));
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertPlainText(QString(tr("Qt Compile Configuration")).append(space).append(QT_VERSION_STR).append("\n"));
    SysInfo.update();
    this->ui->LibrariesDisplay->insertPlainText(headers);
    if(SysInfo.isLinux){
        this->ui->LibrariesDisplay->insertHtml(QString(tr("The <i>xcb</i>")).append(space));
    }
    if(SysInfo.isWindows){
        this->ui->LibrariesDisplay->insertHtml(QString(tr("The <i>windows</i>")).append(space));
    }
    this->ui->LibrariesDisplay->insertPlainText(tr("windowing system"));
}
void AboutInterface::setupAuthors(){
    QLabel *bugAddressLabel = new QLabel(QString(tr("Please report bugs to the address below.")),this->ui->AuthorsTab);
    this->ui->AuthorsLayout->addWidget(bugAddressLabel);
    QSpacerItem space(3,30,QSizePolicy::Fixed,QSizePolicy::Fixed);
    QLabel *Empty = new QLabel(QString("                                  "),this->ui->AuthorsTab);
    this->ui->AuthorsLayout->addWidget(Empty);
    bugAddressLabel->show();
    addAuthor(tr("Beacon1096"),tr("Programming, Core Processing Backend"),"Beacon1096@outlook.com","http://www.codeaha.com/","@Beacon1096");
    addAuthor(tr("Polaris1087"),tr("UI Frontend,Translation"),"Polaris1087@outlook.com","http://www.codeaha.com/","");
    addCredit(tr("Wuhan Education Bureau"),tr("I pretty much have nothing to complain about this"),"","www.whjyj.gov.cn","");
}
void AboutInterface::addAuthor(QString name, QString job, QString emailAddress, QString homePage, QString IM){
    authorsCnt++;
    QLabel *nameLabel = new QLabel(name),*jobLabel = new QLabel(job);
    QFont boldFont=fontLib.targetFont,italicFont=fontLib.targetFont;
    boldFont.setBold(true);
    italicFont.setItalic(true);
    nameLabel->setFont(boldFont);
    jobLabel->setFont(italicFont);
    this->ui->AuthorsLayout->addWidget(nameLabel);
    this->ui->AuthorsLayout->addWidget(jobLabel);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(this);
    nameLabel->show();
    jobLabel->show();
    if(!emailAddress.isEmpty()){
        QPushButton *emailButton = new QPushButton("");
        emailButton->setIcon(QIcon(":/pics/resources/pics/emblems/mail.png"));
        emailButton->setFixedWidth(30);
        emailButton->setFlat(true);
        emailButton->setToolTip(QString(tr("email to:\n")).append(emailAddress));
        buttonsLayout->addWidget(emailButton);
    }
    if(!homePage.isEmpty()){
        QPushButton *homePageButton = new QPushButton("");
        homePageButton->setIcon(QIcon(":/pics/resources/pics/emblems/internet.png"));
        homePageButton->setFixedWidth(30);
        homePageButton->setFlat(true);
        homePageButton->setToolTip(QString(tr("Visit his homepage:\n")).append(homePage));
        buttonsLayout->addWidget(homePageButton);
    }
    if(!IM.isEmpty()){
        QPushButton *IMButton = new QPushButton("");
        IMButton->setIcon(QIcon(":/pics/resources/pics/emblems/im.png"));
        IMButton->setFixedWidth(30);
        IMButton->setFlat(true);
        IMButton->setToolTip(QString(tr("Contact contributer at:\n")).append(IM));
        buttonsLayout->addWidget(IMButton);
    }
    this->ui->AuthorsLayout->insertRow(1+3*authorsCnt,buttonsLayout->layout());
}
void AboutInterface::addCredit(QString name, QString job, QString emailAddress, QString homePage, QString IM){
    creditsCnt++;
    QLabel *nameLabel = new QLabel(name),*jobLabel = new QLabel(job);
    QFont boldFont=fontLib.targetFont,italicFont=fontLib.targetFont;
    boldFont.setBold(true);
    italicFont.setItalic(true);
    nameLabel->setFont(boldFont);
    jobLabel->setFont(italicFont);
    this->ui->ThanksLayout->addWidget(nameLabel);
    this->ui->ThanksLayout->addWidget(jobLabel);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(this);
    nameLabel->show();
    jobLabel->show();
    if(!emailAddress.isEmpty()){
        QPushButton *emailButton = new QPushButton("");
        emailButton->setIcon(QIcon(":/pics/resources/pics/emblems/mail.png"));
        emailButton->setFixedWidth(30);
        emailButton->setFlat(true);
        emailButton->setToolTip(QString(tr("email to:\n")).append(emailAddress));
        buttonsLayout->addWidget(emailButton);
    }
    if(!homePage.isEmpty()){
        QPushButton *homePageButton = new QPushButton("");
        homePageButton->setIcon(QIcon(":/pics/resources/pics/emblems/internet.png"));
        homePageButton->setFixedWidth(30);
        homePageButton->setFlat(true);
        homePageButton->setToolTip(QString(tr("Visit his homepage:\n")).append(homePage));
        buttonsLayout->addWidget(homePageButton);
    }
    if(!IM.isEmpty()){
        QPushButton *IMButton = new QPushButton("");
        IMButton->setIcon(QIcon(":/pics/resources/pics/emblems/im.png"));
        IMButton->setFixedWidth(30);
        IMButton->setFlat(true);
        IMButton->setToolTip(QString(tr("Contact contributer at:\n")).append(IM));
        buttonsLayout->addWidget(IMButton);
    }
    this->ui->ThanksLayout->insertRow(3*authorsCnt,buttonsLayout->layout());
}
void AboutInterface::closeButtonClicked()
{
    this->close();
}
