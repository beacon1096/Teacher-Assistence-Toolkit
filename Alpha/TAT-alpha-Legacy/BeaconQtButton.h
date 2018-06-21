#ifndef BEACONQTBUTTON_H
#define BEACONQTBUTTON_H

#include <QObject>
#include <QPushButton>

class BeaconButton : public QPushButton
{
    Q_OBJECT
public:
    BeaconButton();
    void sendToolTip();
signals:
    void buttonToolTip(QString target);
public slots:
    void toSendToolTip();
};

#endif // BEACONQTBUTTON_H
