#include "DecraptedAboutInterface.h"
#include "ui_DecraptedAboutInterface.h"
#include "main.h"
#include "BeaconQtPlatformInfo.h"
#include "BeaconQtFontLib.h"
#include "TATAboutTextHolder.h"
#include <QString>
#include <QLibraryInfo>
#include <QVersionNumber>
#include <QUrl>
#include <QDebug>
#include <QDesktopServices>
DecraptedAboutInterface::DecraptedAboutInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DecraptedAboutInterface)
{
    ui->setupUi(this);
    connect(ui->AuthorsDiaplay,SIGNAL(anchorClicked(QUrl)),this,SLOT(anchorClickedInAuthorDisplay(QUrl)));
    connect(ui->DetailTab,SIGNAL(currentChanged(int)),this,SLOT(tabSwitched(int)));
    fontLib.initFont();
    fontName.initFontName();
    applyFont(fontLib.targetFont);
    //ui->AboutDisplay->setHtml(aboutTATContent);
    //ui->AboutDisplay->toHtml();
    updateInfo();
}

DecraptedAboutInterface::~DecraptedAboutInterface()
{
    delete ui;
}
void DecraptedAboutInterface::applyFont(QFont target){
    //Label
    ui->ColorLabel->setFont(target);
    //ui->PicLabel
    ui->TATLabel->setFont(target);
    ui->TATFullLabel->setFont(target);
    ui->VersionFullLabel->setFont(target);
    ui->VersionLabel->setFont(target);
    //Diaplay
    ui->AboutDisplay->setFont(target);
    ui->AuthorsDiaplay->setFont(target);
    ui->LibrariesDisplay->setFont(target);
    ui->SysInfoDisplay->setFont(target);
    ui->VersionDetailDisplay->setFont(target);
    ui->ThanksToDisplay->setFont(target);
}
void DecraptedAboutInterface::updateInfo(){
    QString t;
    QString target;
    QVersionNumber QtVersion=QLibraryInfo::version();
    //t=target.append(QString("BuildABI:%1\n").arg(SysInfo.BuildABI));
    t=target.append(QString(tr("BuildABI:")).append(SysInfo.BuildABI).append("\n"));
    t=target.append(QString(tr("BuildArch:")).append(SysInfo.BuildCPUArch).append("\n"));
    t=target.append(QString(tr("CurrentCPUArch:")).append(SysInfo.CuCPUArch).append("\n"));
    t=target.append(QString(tr("OSInfoDefined:")).append(SysInfo.OS).append("\n"));
    t=target.append(QString(tr("OSFriendlyProductName:")).append(SysInfo.OSFormattedProductName).append("\n"));
    t=target.append(QString(tr("OSProductName:")).append(SysInfo.OSProductName).append("\n"));
    t=target.append(QString(tr("OSProductVersion:")).append(SysInfo.OSProductVersion).append("\n"));
    t=target.append(QString(tr("Kernel:")).append(SysInfo.Kernel).append("\n"));
    t=target.append(QString(tr("KernelVersion:")).append(SysInfo.KernelVersion).append("\n"));
    ui->SysInfoDisplay->setText(target);
    target.clear();
    t=target.append(QString(tr("◌Qt ")).append(QtVersion.toString()).append("\n"));
    t=target.append(QString(tr("◌Beacon Qt Utilities Librariy \"Azure\"")).append("\n"));
    if(SysInfo.OS.compare(QString("Linux"))==0){
        t=target.append(QString(tr("◌The xcb windowing system")).append("\n"));
    }
    else if(SysInfo.OS.compare(QString("WIN"))==0){
        t=target.append(QString(tr("◌The Windows windowing system")).append("\n"));
    }
    else if(SysInfo.OS.compare(QString("WINRT"))==0){
        t=target.append(QString(tr("◌The Windows Runtime windowing system")).append("\n"));
    }
    else if(SysInfo.OS.compare(QString("WIN32"))==0){
        t=target.append(QString(tr("◌The Windows windowing system")).append("\n"));
    }
    else if(SysInfo.OS.compare(QString("WIN64"))==0){
        t=target.append(QString(tr("◌The Windows windowing system")).append("\n"));
    }
    if(SysInfo.OS.compare(QString("darwin"))==0){
        t=target.append(QString(tr("◌The Darwin-based(MacOS/OSX/iOS) windowing system")).append("\n"));
    }
    ui->LibrariesDisplay->setText(target);
    target.clear();
    t=target.append(QString("%1\n").arg(version.version));
    t=target.append(QString("%1\n").arg(version.extraBuildInfo));
    t=target.append(QString("%1\n").arg(version.extraIntro));
    ui->VersionDetailDisplay->setText(target);
}

void DecraptedAboutInterface::anchorClickedInAuthorDisplay(const QUrl &url)
{
    QDesktopServices::openUrl(url);
    qDebug() << "opened url";
}
void DecraptedAboutInterface::tabSwitched(int target){
    if(target==2);
}
void DecraptedAboutInterface::flashPicture(QString &target){

}
