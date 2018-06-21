#include "BeaconQtFontLib.h"
#include "BeaconQtPlatformInfo.h"
#include <QFont>
fontLibT fontLib;
fontNameT fontName;
void fontLibT::initFont(){
    fontName.initFontName();
    if(!SysInfo.Kernel.compare("winnt")){
        fontLib.win_Arial.setFamily("Arial");
        fontLib.win_Msyh.setFamily("Microsoft YaHei");
        if(!version.Language.compare("zh_cn")){
            fontLib.targetFont=fontLib.win_Msyh;
            fontLib.targetFontName=fontName.win_Msyh;
        }
        if(!version.Language.compare("en")){
            fontLib.targetFont=fontLib.win_CourierNew;
            fontLib.targetFontName=fontName.win_CourierNew;
        }
    }
    if(!SysInfo.Kernel.compare("linux")){
        fontLib.linux_Notosans.setFamily("Noto Sans");
        fontLib.targetFont=fontLib.linux_Notosans;
        fontLib.targetFontName=fontName.linux_Notosans;
    }
}
void fontNameT::initFontName(){
    win_Arial=QString("Arial");
    win_Msyh=QString("Microfsoft YaHei");
    linux_Notosans=QString("Noto Sans");
    win_CourierNew=QString("Courier New");
}
