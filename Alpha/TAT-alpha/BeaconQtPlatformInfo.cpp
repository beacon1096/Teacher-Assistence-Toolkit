#include "BeaconQtPlatformInfo.h"
#include <QSysInfo>
#include <QtGlobal>
#include <QObject>
SysInfoT SysInfo;
ApplicationVersion version;
void setupVersion(){
    version.setRTM(1);
    version.setLanguage("zh_cn");
    version.setVersion(QString("%1@%2:%3").arg("1.1").arg("Amber").arg(QObject::tr("Proto")));
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
    extraBuildInfo=QString(QObject::tr("Debuging modules intergrated"));
}
void ApplicationVersion::setRelease(){
    extraBuildInfo=QString(QObject::tr("Official Release"));
}
void ApplicationVersion::setPreview(){
    extraBuildInfo=QString(QObject::tr("Preview"));
}
void ApplicationVersion::setRTM(int gen){
    extraBuildInfo=QString(QObject::tr("Preview RTM")).append(" ").append("V%1").arg(QString::number(gen));
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
