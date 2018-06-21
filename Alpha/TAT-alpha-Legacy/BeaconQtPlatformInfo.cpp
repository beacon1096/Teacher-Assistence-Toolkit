#include "BeaconQtPlatformInfo.h"
#include <QSysInfo>
#include <QtGlobal>
#include <QObject>
SysInfoT SysInfo;
ApplicationVersion version;
void setupVersion(){
    version.setRTM(1);
    version.setLanguage("zh_cn");
    version.setVersion(QObject::tr("0.01@Amber:Proto"));
    version.setExtraIntro(QObject::tr("The first public released version of TAT,\na better SLS with GUI implemention."));
    version.setBeaconLibVer(QString("1.0"));
    version.setBeaconLibCodeName(QString("Azure"));
}
void ApplicationVersion::setLanguage(QString target){
    Language=target;
}
void ApplicationVersion::setVersion(QString target){
    version=target;
}
void ApplicationVersion::setDebug(){
    extraBuildInfo=QString("Debuging modules intergrated");
}
void ApplicationVersion::setRelease(){
    extraBuildInfo=QString("Official Release");
}
void ApplicationVersion::setPreview(){
    extraBuildInfo=QString("Preview");
}
void ApplicationVersion::setRTM(int gen){
    extraBuildInfo=QString("Preview RTM V%1").arg(QString::number(gen));
}
void ApplicationVersion::setExtraIntro(QString target){
    extraIntro=target;
}
void ApplicationVersion::setBeaconLibVer(QString target){
    BeaconLibVersion=target;
}
void ApplicationVersion::setBeaconLibCodeName(QString target){
    BeaconLibCodeName=target;
}
