#ifndef TATCOREPROCESSBACKEND_H
#define TATCOREPROCESSBACKEND_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include "BeaconQtFile.h"
#include "TATDebugInterface.h"
#include "TATCoreInterface.h"
#include "TATAboutInterface.h"
class CoreInterface;
struct FileNamesT{
    QString BeaconWdTest;
    QString about_md;
    QString result_csv;
    QString list_csv;
    void init(){
        BeaconWdTest=QString("BeaconBeaconOIClub.doki");
        about_md=QString("about.md");
        result_csv=QString("result.csv");
        list_csv=QString("list.csv");
    }
};
struct FilesT{
    QFile BeaconWdTest;
    QFile about_md;
    QFile result_csv;
    QFile list_csv;
    void init(FileNamesT &filenames){
        openFile(BeaconWdTest,filenames.BeaconWdTest,'w');
        openFile(about_md,filenames.about_md,'r');
        openFile(result_csv,filenames.result_csv,'w');
        openFile(list_csv,filenames.list_csv,'r');
    }
};
struct objectT{
    QApplication *app;
    CoreInterface *core;
    AboutInterface *about;
    DebugInterface *debug;
    QString *chartOut;
};

struct CoreProcessBackend
{
    void setupBackend();
    void loadStudentInfo();
    void convertAllResToInt();
    void loadFileStream();
    void showSelectedStudent(QString subString);
    void writeResultChart();
    void selectClass();
    void probeClass();
    void loadSettings();
    void updateInterface();
    void modifyStudentRes(QString& command);
    void sortList(QString method);
    objectT objects;
    FilesT files;
    FileNamesT filenames;
    QString chartStream;   
};

extern CoreProcessBackend procBackend;
#endif // TATCOREPROCESSBACKEND_H
