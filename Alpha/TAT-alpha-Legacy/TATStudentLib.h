#ifndef TATSTULIB_H
#define TATSTULIB_H
#include <QStringList>
#include <QDebug>
#include <QString>
struct studentInfo{
    QStringList name;
    //name.at(0) is a full name by default
    QStringList res;
    int resSum;
    int ranking;
    QString fullName(){
        return name.at(0);
    }
    int resToInt(){
        resSum=0;
        QStringList::iterator it;
        for(it=res.begin();it!=res.end();it++){
            resSum+=it->toInt();
        }
        qDebug() << "[r2I]convert complete:res=" << resSum;
        return resSum;
    }
    QString genResQStr(){
        QString target;
        int lim=res.size();
        for(int i=0;i<lim;i++){
            target.append(QString("%1,").arg(res[i]));
        }
        return target;
    }
};
struct classInfoT{
    int serial;
    int studentCount;
    int classId(){
        return serial;
    }
    int stuCnt(){
        return studentCount;
    }
};
bool cmpByNumeral(studentInfo a,studentInfo b){
    return a.resSum>b.resSum;
}
bool cmpByDictional(studentInfo a,studentInfo b){
    QString tmp1=a.res.at(0),tmp2=b.res.at(0);
    if(tmp1.compare(tmp2)>0)return false;
    else return true;
}
#endif // TATSTULIB_H
