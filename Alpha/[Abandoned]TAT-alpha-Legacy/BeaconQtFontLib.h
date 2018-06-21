#ifndef BEACONQTFONTLIB_H
#define BEACONQTFONTLIB_H
#include <QFont>
class fontLibT{
public:
    QFont win_Arial,win_Msyh,win_CourierNew;
    QFont linux_Notosans,linux_TscuComic;
    QFont targetFont;
    QString targetFontName;
    void initFont();
    void setTargetName(QString target){
        targetFontName=target;
    }
    void setTargetFont(QFont target){
        targetFont=target;
    }
};
struct fontNameT{
    QString win_Arial,win_Msyh,win_CourierNew;
    QString linux_Notosans,linux_TucuComic;
    void initFontName();
};
extern fontLibT fontLib;
extern fontNameT fontName;
#endif // BEACONQTFONTLIB_H
