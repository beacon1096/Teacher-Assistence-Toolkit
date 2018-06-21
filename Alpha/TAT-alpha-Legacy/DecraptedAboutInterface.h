#ifndef DECRAPTEDABOUTINTERFACE_H
#define DECRAPTEDABOUTINTERFACE_H

#include <QMainWindow>

namespace Ui {
class DecraptedAboutInterface;
}

class DecraptedAboutInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit DecraptedAboutInterface(QWidget *parent = 0);
    ~DecraptedAboutInterface();
    void updateInfo();
    void applyFont(QFont target);

private slots:
    void tabSwitched(int target);
    void flashPicture(QString &target);
    void anchorClickedInAuthorDisplay(const QUrl &arg1);

private:
    Ui::DecraptedAboutInterface *ui;
};

#endif // DECRAPTEDABOUTINTERFACE_H
