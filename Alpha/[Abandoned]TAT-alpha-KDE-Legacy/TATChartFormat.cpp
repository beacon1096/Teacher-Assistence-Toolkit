#include "TATChartFormat.h"
#include "TATCoreProcessBackend.h"
void TATChartPrepare(){
    if(!chartInfo.header.isEmpty())
        procBackend.objects.chartOut->append(QString("%1\n").arg(chartInfo.header));
}
