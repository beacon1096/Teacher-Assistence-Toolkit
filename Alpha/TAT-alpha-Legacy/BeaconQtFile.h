#ifndef BEACONQTLIB_H
#define BEACONQTLIB_H
#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>
using namespace std;
bool openFile(QFile& file,QString name,QChar IOMode);
void bundleIO(QFile& file,QTextStream& str);
QString str2qstr(const string str);
string qstr2str(const QString qstr);
#endif // BEACONQTLIB_H
