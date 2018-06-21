#ifndef TATEXTRAINFO_H
#define TATEXTRAINFO_H
#include <QString>
#include <QSysInfo>
#include <QtGlobal>
#include <QObject>
void setupVersion();
struct ApplicationVersion
{
    QString Language;
    QString version;
    QString extraBuildInfo;
    QString BeaconLibVersion;
    QString BeaconLibCodeName;
    QString extraIntro;
    void setLanguage(QString target);
    void setVersion(QString target);
    void setDebug();
    void setRelease();
    void setBeaconLibCodeName(QString target);
    void setPreview();
    void setRTM(int gen);
    void setExtraIntro(QString target);
    void setBeaconLibVer(QString target);
};
struct SysInfoT
{
QString OS,Kernel,KernelVersion;
QString BuildABI,BuildCPUArch;
QString CuCPUArch;
QString HostName;
QString OSProductName,OSFormattedProductName;
QString OSProductVersion;
bool isWindows;
bool isLinux;
void update(){
    BuildABI=QSysInfo::buildAbi();
    BuildCPUArch=QSysInfo::buildCpuArchitecture();
    CuCPUArch=QSysInfo::currentCpuArchitecture();
    Kernel=QSysInfo::kernelType();
    KernelVersion=QSysInfo::kernelVersion();
    HostName=QSysInfo::machineHostName();
    OSFormattedProductName=QSysInfo::prettyProductName();
    OSProductName=QSysInfo::productType();
    OSProductVersion=QSysInfo::productVersion();
    #ifdef Q_OS_UNIX
    OS=QString("UNIX");
    #endif
    #ifdef Q_OS_LINUX
    OS=QString("Linux");
    isLinux=true;
    #endif
    #ifdef Q_OS_DARWIN
    OS=QString("DARWIN");
    #endif
    #ifdef Q_OS_MACOS
    OS=QString("MACOS");
    #endif
    #ifdef Q_OS_NETBSD
    OS=QString("NETBSD");
    #endif
    #ifdef Q_OS_OPENBSD
    OS=QString("OPENBSD");
    #endif
    #ifdef Q_OS_SOLARIS
    OS=QString("SOLARIS");
    #endif
    #ifdef Q_OS_WIN
    OS=QString("WIN");
    isWindows=true;
    #endif
    #ifdef Q_OS_WINRT
    OS=QString("WINRT");
    isWindows=true;
    #endif
    #ifdef Q_OS_WIN32
    OS=QString("WIN32");
    isWindows=true;
    #endif
    #ifdef Q_OS_WIN64
    OS=QString("WIN64");
    isWindows=true;
    #endif
    #ifdef Q_OS_TVOS
    OS=QString("TVOS");
    #endif
    #ifdef Q_OS_IOS
    OS=QString("IOS");
    #endif
    #ifdef Q_OS_CYGWIN
    OS=QString("CYGWIN");
    #endif
    #ifdef Q_OS_ANDROID
    OS=QString("ANDROID");
    #endif
    }
};
extern SysInfoT SysInfo;
extern ApplicationVersion version;
#endif // TATEXTRAINFO_H
