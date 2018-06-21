#include "TATDebugInterface.h"
#include "ui_TATDebugInterface.h"
#include "BeaconQtPlatformInfo.h"
#include "TATCoreProcessBackend.h"
#include <QFontDatabase>
#include <KCoreAddons>
#include <KProcess>
#include <QStandardPaths>
DebugInterface::DebugInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DebugInterface)
{
    ui->setupUi(this);
    updateBuildInfo();
    updateFontInfo();
    updateProcessInfo();
}

DebugInterface::~DebugInterface()
{
    delete ui;
}
void DebugInterface::updateProcessInfo(){
    QString target,t;
    t=target.append(QString("Qt Standard Paths:%1\n").arg(QStandardPaths::GenericDataLocation));
    t=target.append(QString("KF5(KDE Framework 5) Version:%1\n").arg(KCoreAddons::versionString()));
    ui->LibDisplay->setText(target);
}
void DebugInterface::updateBuildInfo(){
    QString t;
    QString target;
    t=target.append(QString(tr("BuildABI:")).append(SysInfo.BuildABI).append("\n"));
    t=target.append(QString(tr("BuildArch:")).append(SysInfo.BuildCPUArch).append("\n"));
    t=target.append(QString(tr("CurrentCPUArch:")).append(SysInfo.CuCPUArch).append("\n"));
    t=target.append(QString(tr("OSInfoDefined:")).append(SysInfo.OS).append("\n"));
    t=target.append(QString(tr("OSFriendlyProductName:")).append(SysInfo.OSFormattedProductName).append("\n"));
    t=target.append(QString(tr("OSProductName:")).append(SysInfo.OSProductName).append("\n"));
    t=target.append(QString(tr("OSProductVersion:")).append(SysInfo.OSProductVersion).append("\n"));
    t=target.append(QString(tr("Kernel:")).append(SysInfo.Kernel).append("\n"));
    t=target.append(QString(tr("KernelVersion:")).append(SysInfo.KernelVersion).append("\n"));
    ui->BuildInfoDisplay->setText(target);
}
void DebugInterface::updateFontInfo(){
    QFontDatabase database;
    QString res;
    foreach (const QString &family, database.families())
    {
        res.append(QString("%1\n").arg(family));
    }
    ui->FontDisplay->setText(res);
}
