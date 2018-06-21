#ifndef MAIN_H
#define MAIN_H
#include "TATAboutInterface.h"
#include "TATCoreInterface.h"
#include "DecraptedAboutInterface.h"
#include "BeaconQtPlatformInfo.h"
int main(int argc, char *argv[]);
void showQt();

extern QFont targetFont;
extern AboutInterface *abIp;
extern DecraptedAboutInterface *deabIp;
extern SysInfoT SysInfo;
extern ApplicationVersion version;
#endif //MAIN_H
