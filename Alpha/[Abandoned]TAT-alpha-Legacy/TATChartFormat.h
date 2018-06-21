#ifndef TATCHARTFORMAT_H
#define TATCHARTFORMAT_H
#include <QString>

struct chartInfoT{
    QString header;
    void init(){
        header="";
    }
};
extern chartInfoT chartInfo;
void TATChartPrepare();
#endif // TATCHARTFORMAT_H
