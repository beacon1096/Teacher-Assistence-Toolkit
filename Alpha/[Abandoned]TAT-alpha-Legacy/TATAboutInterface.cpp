#include "TATAboutInterface.h"
#include "ui_TATAboutInterface.h"
#include "BeaconQtPlatformInfo.h"
#include "BeaconQtString.h"
#include "BeaconQtFontLib.h"
#include "BeaconQtButton.h"
#include <QtCore>
#include <QLabel>
#include <QMessageBox>
#include <QSizePolicy>
#include <QDialog>
#include <QDebug>
#include <QSpacerItem>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <QHBoxLayout>
AboutInterface::AboutInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutInterface)
{
    ui->setupUi(this);
    connect(this->ui->CloseButton,SIGNAL(clicked()),this,SLOT(closeButtonClicked()));
    ApplyFont(fontLib.targetFont);
    init();
}

AboutInterface::~AboutInterface()
{
    delete ui;
}
void AboutInterface::showToolTip(QString target){
    qDebug() << "[showToolTip]get " << target;
    QString a,b;
    stringUtil.splitWithChar(':',target,a,b);
    qDebug() << "[showToolTip]dissemble:b=" << b;
    b.replace("\n","");
    QMessageBox::StandardButton note = QMessageBox::information(NULL,tr("About Contributor"),QString("%1:\n%2").arg(tr("You may contact this contributor by")).arg(b));
}
void AboutInterface::SeekURL(QString proc){
    qDebug() << "[SeekURL]get " << proc;
    QString a,b;
    stringUtil.splitWithChar(':',proc,a,b);
    qDebug() << "[SeekURL]dissemble:b=" << b;
    b.replace("\n","");
    QDesktopServices::openUrl(QUrl(b));

}
void AboutInterface::ApplyFont(QFont &Target){
    fontName.initFontName();
    fontLib.initFont();
    QFont Title=Target;Title.setPointSize(12);
    QFont subTitle=Target;subTitle.setPointSize(10);
    this->ui->VersionLabel->setFont(subTitle);
    this->ui->MainTab->setFont(Target);
    this->ui->AboutDisplay->setFont(Target);
    this->ui->LibrariesDisplay->setFont(Target);
    this->ui->TATLabel->setFont(Title);
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
    versionOutput.append(QString("%1<br>").arg(version.version));
    versionOutput.append(QString("%1%2<br>").arg(tr("Build date:")).arg(data.buildDate.toString()));
    versionOutput.append(QString("%1%2<br>").arg(tr("Build time:")).arg(data.buildTime.toString()));
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
QString AboutInterface::AboutContent(){
    return this->ui->AboutDisplay->toHtml();
}
QString HtmlProcFont(QString target,QString Font){
    return QString("<span style=\" font-family:'%1'; font-size:9pt; \">%2</span>").arg(Font).arg(target);
}
void AboutInterface::setupAbout(){
    fontName.initFontName();
    fontLib.initFont();
    QString a;
    this->ui->AboutDisplay->clear();
    this->ui->AboutDisplay->insertHtml(QString("%1<br><br>").arg(HtmlProcFont(data.shortDescription,fontLib.targetFontName)));
    this->ui->AboutDisplay->insertHtml(QString("%1<br><br>").arg(HtmlProcFont(data.otherText,fontLib.targetFontName)));
    this->ui->AboutDisplay->insertHtml(QString("%1<br><br>").arg(HtmlProcFont(data.copyrightStatement,fontLib.targetFontName)));
    this->ui->AboutDisplay->insertHtml(QString("%1<br>").arg(HtmlProcFont(QString("<a href=\"%1\">").arg(data.homepage).append("Visit Homepage:").append(data.homepage).append("</a><br>"),fontLib.targetFontName)));
    this->ui->AboutDisplay->insertHtml(QString("%1<br><br>").arg(HtmlProcFont(data.license,fontLib.targetFontName)));
}
void AboutInterface::setupLibraries(){
    QString tmp;
    QString headers="    ⡢";QString space=" ";
    QVersionNumber QtVersion=QLibraryInfo::version();
    this->ui->LibrariesDisplay->clear();
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertHtml(QString("%1 ").arg(HtmlProcFont(QString(tr("Beacon Qt Library:")).append(version.BeaconLibVersion),fontLib.targetFontName)));
    this->ui->LibrariesDisplay->insertHtml(QString("%1<br>").arg(HtmlProcFont(QString("<i>(%1)</i>").arg(version.BeaconLibCodeName),fontLib.targetFontName)));
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertHtml(QString("%1<br>").arg(HtmlProcFont(tr("Qt Runtime").append(space).append(QtVersion.toString()).append("\n"),fontLib.targetFontName)));
    this->ui->LibrariesDisplay->insertPlainText(headers);
    this->ui->LibrariesDisplay->insertHtml(QString("%1<br>").arg(HtmlProcFont(tr("Qt Compile Configuration").append(space).append(QT_VERSION_STR).append("\n"),fontLib.targetFontName)));
    SysInfo.update();
    this->ui->LibrariesDisplay->insertPlainText(headers);
    if(SysInfo.isLinux){
        tmp.append(QString(tr("The <i>xcb</i>")).append(space));
    }
    if(SysInfo.isWindows){
        tmp.append(QString(tr("The <i>windows</i>")).append(space));
    }
    this->ui->LibrariesDisplay->insertHtml(QString("%1<br>").arg(HtmlProcFont(tmp.append(tr("windowing system")),fontLib.targetFontName)));
}
QString AboutInterface::titleFont(){
    return this->ui->TATLabel->font().family();
}

void AboutInterface::setupAuthors(){
    QLabel *bugAddressLabel = new QLabel(QString(tr("Please report bugs to the address below.")),this->ui->AuthorsTab);
    bugAddressLabel->setFont(fontLib.targetFont);
    this->ui->AuthorsLayout->addWidget(bugAddressLabel);
    QSpacerItem space(3,30,QSizePolicy::Fixed,QSizePolicy::Fixed);
    QLabel *Empty = new QLabel(QString("                                  "),this->ui->AuthorsTab);
    this->ui->AuthorsLayout->addWidget(Empty);
    bugAddressLabel->show();
    addAuthor(tr("Beacon1096"),tr("Programming, Core Processing Backend"),"Beacon1096@outlook.com","http://www.codeaha.com/","Github->Beacon1096,QQ->505173168");
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
        BeaconButton *emailButton = new BeaconButton();
        emailButton->setIcon(QIcon(":/pics/resources/pics/emblems/mail.png"));
        emailButton->setFixedWidth(30);
        emailButton->setFlat(true);
        emailButton->setToolTip(QString(tr("email to:\n")).append("mailto:").append(emailAddress));
        buttonsLayout->addWidget(emailButton);
        connect(emailButton,SIGNAL(clicked()),emailButton,SLOT(toSendToolTip()));
        connect(emailButton,SIGNAL(buttonToolTip(QString)),this,SLOT(SeekURL(QString)));
    }
    if(!homePage.isEmpty()){
        BeaconButton *homePageButton = new BeaconButton();
        homePageButton->setIcon(QIcon(":/pics/resources/pics/emblems/internet.png"));
        homePageButton->setFixedWidth(30);
        homePageButton->setFlat(true);
        homePageButton->setToolTip(QString(tr("Visit his homepage:\n")).append(homePage));
        buttonsLayout->addWidget(homePageButton);
        connect(homePageButton,SIGNAL(clicked()),homePageButton,SLOT(toSendToolTip()));
        connect(homePageButton,SIGNAL(buttonToolTip(QString)),this,SLOT(SeekURL(QString)));
    }
    if(!IM.isEmpty()){
        BeaconButton *IMButton = new BeaconButton();
        IMButton->setIcon(QIcon(":/pics/resources/pics/emblems/im.png"));
        IMButton->setFixedWidth(30);
        IMButton->setFlat(true);
        IMButton->setToolTip(QString(tr("Contact contributer at:\n")).append(IM));
        buttonsLayout->addWidget(IMButton);
        connect(IMButton,SIGNAL(clicked()),IMButton,SLOT(toSendToolTip()));
        connect(IMButton,SIGNAL(buttonToolTip(QString)),this,SLOT(showToolTip(QString)));
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
        BeaconButton *emailButton = new BeaconButton();
        emailButton->setIcon(QIcon(":/pics/resources/pics/emblems/mail.png"));
        emailButton->setFixedWidth(30);
        emailButton->setFlat(true);
        emailButton->setToolTip(QString(tr("email to:\n")).append("mailto:").append(emailAddress));
        buttonsLayout->addWidget(emailButton);
        connect(emailButton,SIGNAL(clicked()),emailButton,SLOT(toSendToolTip()));
        connect(emailButton,SIGNAL(buttonToolTip(QString)),this,SLOT(SeekURL(QString)));
    }
    if(!homePage.isEmpty()){
        BeaconButton *homePageButton = new BeaconButton();
        homePageButton->setIcon(QIcon(":/pics/resources/pics/emblems/internet.png"));
        homePageButton->setFixedWidth(30);
        homePageButton->setFlat(true);
        homePageButton->setToolTip(QString(tr("Visit his homepage:\n")).append(homePage));
        buttonsLayout->addWidget(homePageButton);
        connect(homePageButton,SIGNAL(clicked()),homePageButton,SLOT(toSendToolTip()));
        connect(homePageButton,SIGNAL(buttonToolTip(QString)),this,SLOT(SeekURL(QString)));
    }
    if(!IM.isEmpty()){
        BeaconButton *IMButton = new BeaconButton();
        IMButton->setIcon(QIcon(":/pics/resources/pics/emblems/im.png"));
        IMButton->setFixedWidth(30);
        IMButton->setFlat(true);
        IMButton->setToolTip(QString(tr("Contact contributer at:\n")).append(IM));
        buttonsLayout->addWidget(IMButton);
        connect(IMButton,SIGNAL(clicked()),IMButton,SLOT(toSendToolTip()));
        connect(IMButton,SIGNAL(buttonToolTip(QString)),this,SLOT(showToolTip(QString)));
    }
    this->ui->ThanksLayout->insertRow(3*authorsCnt,buttonsLayout->layout());
}
void AboutInterface::closeButtonClicked()
{
    this->close();
}
