#ifndef BEACONQTABOUTDATA_H
#define BEACONQTABOUTDATA_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDateTime>
#include <QLocale>

class BeaconAboutData : public QObject
{
    Q_OBJECT
public:
    BeaconAboutData();
    QDate buildDate;
    QTime buildTime;
    QString componentName;
    QString displayName;
    QString version;
    QString shortDescription;
    QString copyrightStatement;
    QString homepage;
    QString license;
    QString bugAddress;
    QString ocsProvider;
    QString programLogo;
    QString versionOutput;
    QString otherText;
    void setComponentName(QString target);
    void setVersion(QString target);
    void setShortDescription(QString target);
    void setCopyrightStatement(QString target);
    void setHomepage(QString target);
    void setBugAddress(QString target);
    void setLicense(QString target);
    void setDisplayName(QString target);
    void setOcsProvider(QString target);
    void setProgramLogo(QString target);
    void setVersionOutput(QString target);
    void setOtherText(QString target);
};

#endif // BEACONQTABOUTDATA_H
