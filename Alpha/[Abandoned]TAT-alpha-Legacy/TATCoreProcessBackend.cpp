#include "TATCoreProcessBackend.h"
#include "TATStudentLib.h"
#include "TATChartFormat.h"
#include "BeaconQtFile.h"
#include "BeaconQtString.h"
#include "TATCoreProcessBackendDebugSwitcher.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <algorithm>
#include <QList>
using namespace std;
//operationCore
FileNamesT filenames;
FilesT files;
objectT objects;
QString toChart;
//dataCore
QList<studentInfo> students;
classInfoT classInfo;
chartInfoT chartInfo;
int filledCnt=0;
CoreProcessBackend procBackend;
void CoreProcessBackend::convertAllResToInt(){
    QList<studentInfo>::iterator it;
    for(it=students.begin();it!=students.end();it++){
        it->resToInt();
    }
}
void CoreProcessBackend::loadStudentInfo(){
    studentInfo tmpInfo;
    QTextStream strm;
    QString currentLine,tmpStr;
    QStringList tmpList;
    int stuCnt=0;
    bool classSelected=false;
    bundleIO(files.list_csv,strm);
    while(!strm.atEnd()){
        currentLine=strm.readLine();
        if(currentLine.isEmpty())continue;
        if(!classSelected){//class was not found yet
            tmpStr=currentLine.section(",",0,0);
            if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]tmpStr=" << tmpStr;
            if(tmpStr[0]=='#'){
                if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]Seek:#*";
                tmpStr.remove(0,1);
                if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]rm '#',got int=" << tmpStr.toInt();
                if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]from str:" << tmpStr;
                if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]targetClassId=" << classInfo.classId();
                if(classInfo.classId()==tmpStr.toInt()){
                    classSelected=true;
                    if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo]Fetch Class" << classInfo.classId();
                }
            }
        }
        else{//a specified class was seen in file
            tmpList=currentLine.split(',',QString::SkipEmptyParts);
            tmpStr=tmpList.at(0);
            if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo-P2]targetStudent: " << tmpList;
            if(DEBUGLOADSTUINFO)qDebug() << "[LoadStudentInfo-P2]samplingString:" << tmpStr;
            if(!tmpStr.isEmpty() && tmpStr[0]!='#'){
                stuCnt++;
                tmpInfo.name=tmpList;
                students.append(tmpInfo);
            }
            else {
                classInfo.studentCount=stuCnt;
                break;
            }//end of list
        }
    }
    classInfo.studentCount=stuCnt;
}
void CoreProcessBackend::showSelectedStudent(QString subString){
    subString=subString.section(' ',0,0);
    QString content;
    int lim=classInfo.stuCnt();
    int cnt=0;
    if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]lim:" << lim;
    bool filter=!subString.isEmpty();
    if(!filter){
        for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
            if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]Cur:" << it->name;
            content.append(it->fullName());
            if(!it->res.isEmpty()){
                content.append(" ");
                content.append(it->genResQStr());
            }
            content.append("\n");
            cnt++;
        }
        objects.core->writeCoreDisplay(content);
        return;
    }
    for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
        if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]counting:" << it->name;
            for(int j=0;j<it->name.size();j++){
                if(it->name.at(j).indexOf(subString)!=-1){
                    cnt++;
                    break;
                }
            }
    }
    for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
        if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]Cur:" << it->name;
        for(int j=0;j<it->name.size();j++){
            if(it->name.at(j).indexOf(subString)!=-1){
                if(it->res.isEmpty()){
                content.append(it->fullName());
                if(cnt==1)content.append("<-");
                content.append('\n');
                if(cnt<=5)content.append(QString("(%1)\n").arg(it->name.join(" ")));
                break;
                }
            }
        }
    }
    for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
        if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]Cur:" << it->name;
        for(int j=0;j<it->name.size();j++){
            if(it->name.at(j).indexOf(subString)!=-1){
                if(!it->res.isEmpty()){
                content.append(it->fullName());
                content.append(QString(" %1\n").arg(it->res.join(",")));
                if(cnt<=5)content.append(QString("(%1)\n").arg(it->name.join(" ")));
                break;
                }
            }
        }
    }
    if(DEBUGSHOWSTUINFO)qDebug() << "[showStudent]Update:cnt=" << cnt;
    objects.core->writeCoreDisplay(content);
    return;
}
void CoreProcessBackend::writeResultChart(){
    objects.chartOut=&toChart;
    files.result_csv.close();
    files.result_csv.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    TATChartPrepare();
    for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
        toChart.append(QString("%1,%2\n").arg(it->fullName()).arg(it->genResQStr()));
    }
    QTextStream strm;
    bundleIO(files.result_csv,strm);
    strm << toChart;
    objects.core->updatePreviewDisplay(toChart);
    strm.flush();
    toChart.clear();
}
void CoreProcessBackend::modifyStudentRes(QString& command){
    QList<studentInfo>::iterator target=students.end()+1;
    if(stringUtil.equal(command,"print",false)){
        writeResultChart();
        return;
    }
    if(stringUtil.equal(command,"ls",false)){
        showSelectedStudent(QString(""));
        return;
    }
    QString name,res;
    if(!stringUtil.splitWithSpace(command,name,res)){
        objects.core->writeCoreDisplay(QObject::tr("Unacceptable Command:No seperator"));
        return;
    }
    if(DEBUGMODIFYSTUINFO)qDebug() << "name:" << name;
    if(DEBUGMODIFYSTUINFO)qDebug() << "res:" << res;
    for(QList<studentInfo>::iterator it=students.begin();it!=students.end();it++){
        if(stringUtil.list.exist(it->name,name)){
            target=it;
            break;
        }
    }
    if(target==students.end()+1){
        objects.core->writeCoreDisplay(QObject::tr("Unacceptable Command:Could not find a target student"));
        return;
    }
    if(target->res.isEmpty())filledCnt++;
    target->res=res.split(',');
    objects.core->writeCoreEditBar("");
    objects.core->updateProgressBar(filledCnt,classInfo.stuCnt());
    if(filledCnt==classInfo.stuCnt()){
        QMessageBox::StandardButton rb = QMessageBox::question(NULL, QObject::tr("Complete"), QObject::tr("Do you want to print the chart and proceed?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            writeResultChart();
            objects.core->changeTab(2);
        }
    }
    return;
}
void CoreProcessBackend::loadFileStream(){
    if(DEBUGLOADFS)qDebug() << "[TATFileBackendInit]Luke FileWalker on going";
    filenames.init();
    files.init(filenames);
}
void CoreProcessBackend::setupBackend(){
    objects.chartOut=&chartStream;
    loadFileStream();
    probeClass();
}
void CoreProcessBackend::updateInterface(){
    loadStudentInfo();
    showSelectedStudent(QString(""));
}
void CoreProcessBackend::probeClass(){
    QTextStream strm;
    QString currentLine,tmpStr;
    QStringList tmpList;
    bundleIO(files.list_csv,strm);
    while(!strm.atEnd()){
        currentLine=strm.readLine();
        if(currentLine.isEmpty())continue;
            tmpStr=currentLine.section(",",0,0);
            if(DEBUGPROBECLASS)qDebug() << "[probeClass]tmpStr=" << tmpStr;
            if(tmpStr[0]=='#'){
                if(DEBUGPROBECLASS)qDebug() << "[probeClass]Seek:#*";
                tmpStr.remove(0,1);
                if(DEBUGPROBECLASS)qDebug() << "[probeClass]rm '#',got int=" << tmpStr.toInt();
                if(DEBUGPROBECLASS)qDebug() << "[probeClass]from str:" << tmpStr;
                if(DEBUGPROBECLASS)qDebug() << "[probeClass]targetClassId=" << classInfo.classId();
                objects.core->addClass(tmpStr.toInt());
            }
    }
    files.list_csv.close();
    openFile(files.list_csv,"list.csv",'r');
}
void CoreProcessBackend::loadSettings(){
    classInfo.serial=objects.core->selectedClass();
    if(DEBUGLOADSETTINGS)qDebug() << "[loadSettings]serial:" << classInfo.serial << "sel Class:" << objects.core->selectedClass();
    chartInfo.header=objects.core->chartHeader();
}
void CoreProcessBackend::sortList(QString method){
    if(DEBUGSORTLIST)qDebug() << "[sortList]triggered,method:" << method;
    if(!method.compare("Numeral")){
        if(DEBUGSORTLIST)qDebug() << "[sortList]Numeral started";
        convertAllResToInt();
        sort(students.begin(),students.end(),cmpByNumeral);
    }
    if(!method.compare("Dictional")){
        if(DEBUGSORTLIST)qDebug() << "[sortList]Dictional started";
        sort(students.begin(),students.end(),cmpByDictional);
    }
    writeResultChart();
}
