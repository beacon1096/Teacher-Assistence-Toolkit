#ifndef TATDEBUGINTERFACE_H
#define TATDEBUGINTERFACE_H

#include <QMainWindow>

namespace Ui {
class DebugInterface;
}

class DebugInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugInterface(QWidget *parent = 0);
    ~DebugInterface();
    void updateBuildInfo();
    void updateFontInfo();
    void updateProcessInfo();
    void updateAboutContent();

private slots:
    void on_GetAbout_clicked();

private:
    Ui::DebugInterface *ui;
};

#endif // TATDEBUGINTERFACE_H
