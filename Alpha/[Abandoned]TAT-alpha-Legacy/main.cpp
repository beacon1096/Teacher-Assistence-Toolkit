#include "TATCoreInterface.h"
#include "TATAboutInterface.h"
#include "TATAboutInterface.h"
#include "main.h"
#include "BeaconQtPlatformInfo.h"
#include "TATCoreProcessBackend.h"
#include "DecraptedAboutInterface.h"
#include "TATAboutInterface.h"
#include "BeaconQtFontLib.h"
#include "TATDebugInterface.h"
#include <QApplication>
#include <QtCore>
#include <QObject>
#include <QDebug>
#include <QTranslator>
AboutInterface *abIp;
DecraptedAboutInterface *deabIp;
DebugInterface *gbdIp;
void showQt(){
    procBackend.objects.app->aboutQt();
}
int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE("pics.qrc");
    fontName.initFontName();
    fontLib.initFont();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    setupVersion();
    QApplication a(argc, argv);
    QTranslator trans;
    trans.load("zh_cn.qm");
    a.installTranslator(&trans);
    SysInfo.update();
    CoreInterface w;
    AboutInterface abI;
    DecraptedAboutInterface deabI;
    DebugInterface dbgI;
    procBackend.objects.app=&a;
    procBackend.objects.core=&w;
    procBackend.objects.about=&abI;
    procBackend.objects.debug=&dbgI;
    procBackend.setupBackend();
    abIp=&abI;
    deabIp=&deabI;
    w.show();

    return a.exec();
}
