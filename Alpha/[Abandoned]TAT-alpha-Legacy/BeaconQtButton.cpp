#include "BeaconQtButton.h"

BeaconButton::BeaconButton()
{

}
void BeaconButton::toSendToolTip(){
    sendToolTip();
}
void BeaconButton::sendToolTip(){
    QString target=this->toolTip();
    emit buttonToolTip(target);
}

