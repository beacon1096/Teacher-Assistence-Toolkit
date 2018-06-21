#ifndef TATCOREINTERFACE_H
#define TATCOREINTERFACE_H

#include <QMainWindow>

struct CoreProcessBackend;
namespace Ui {
class CoreInterface;
}

class CoreInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoreInterface(QWidget *parent = 0);
    ~CoreInterface();
    void writeCoreDisplay(QString target);
    void writeCoreEditBar(QString target);
    void updateProgressBar(int cnt,int total);
    void addClass(int x);
    int selectedClass();
    void applyFont(QFont target);
    void updatePreviewDisplay(QString target);
    QString chartHeader();
    void changeTab(int target);
    Ui::CoreInterface *ui;

private slots:
    void TechnicalInfoTriggered();
    void clickedProcede();
    void CLITextChanged(const QString &arg1);
    void aboutQtTriggered();
    void exitActionTriggered();
    void clickedOKButton();
    void sortButtonClicked();
    void AboutTATTriggered();

private:

    QString lynz;
};

#endif // TATCOREINTERFACE_H
