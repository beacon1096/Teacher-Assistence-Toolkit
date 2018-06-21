#ifndef BEACONQTSTRING_H
#define BEACONQTSTRING_H
#include <QString>
#include <QStringList>
#include <QColor>
struct listT{
    bool exist(QStringList& list,QString& target){
        if(-1 == list.indexOf(target)){
            return false;
        }
        else return true;
    }
};
struct stringsT{
    bool splitWithSpace(QString& src,QString& dest1,QString& dest2){
        int spacePls=src.indexOf(" ");
        if(spacePls==-1)return false;
        dest1=src.left(spacePls);
        dest2=src.right(src.length()-spacePls-1);
        return true;
    }
    bool splitWithChar(char spliter,QString& src,QString& dest1,QString& dest2){
        int spacePls=src.indexOf(spliter);
        if(spacePls==-1)return false;
        dest1=src.left(spacePls);
        dest2=src.right(src.length()-spacePls-1);
        return true;
    }
    bool equal(QString a,QString b,bool caseSensitive){
        if(caseSensitive)
            return !QString::compare(a,b,Qt::CaseSensitive);
        else
            return !QString::compare(a,b,Qt::CaseInsensitive);
    }
    listT list;
};
extern stringsT stringUtil;
void stringToHtmlFilter(QString &str);
#endif // BEACONQTSTRING_H
