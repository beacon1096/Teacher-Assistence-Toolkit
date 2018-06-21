#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <string>
#include "BeaconQtFile.h"
using namespace std;
bool DEBUGSWITCHER=false;
bool openFile(QFile& file,QString name,QChar IOMode){
    bool res;
    file.setFileName(name);
    if(DEBUGSWITCHER)qDebug() << name << "exist?" << file.exists();
    if(IOMode=='r'){
        res=file.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    if(IOMode=='w'){
        res=file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    }
    if(DEBUGSWITCHER)qDebug() << "[openFire]Opening:" << name << " " << res;
    if(!res && DEBUGSWITCHER)qDebug() << "error:" << file.error();
    return res;
}
void bundleIO(QFile& file,QTextStream& str){
    str.setDevice(&file);
    if(DEBUGSWITCHER)qDebug() << "[bundleIO]file:" << file.fileName();
}
QString str2qstr(const string str)
{
    return QString::fromLocal8Bit(str.data());
}

string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}
