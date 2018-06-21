#ifndef TATaboutInterfaceLegacyKDE_H
#define TATaboutInterfaceLegacyKDE_H

#include <QObject>
#include <KAboutData>
struct TATAboutData {
    KAboutData data=KAboutData("","","");
    QObject adTrans;
    //TATAboutData(QString componentName,QString displayName,QString version);
    void init();
    void show();
    QString note;
};

extern TATAboutData aboutData;
#endif // AboutInterfaceLegacyKDE_H
