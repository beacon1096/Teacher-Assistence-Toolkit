#include "TATCoreInterface.h"
#include "ui_TATCoreInterface.h"
#include "TATAboutInterface.h"
#include "BeaconQtFontLib.h"
#include "BeaconQtPlatformInfo.h"
#include "main.h"
#include "TATCoreProcessBackend.h"
#include "TATAboutInterface.h"
#include "TATDebugInterface.h"
#include <QMessageBox>
#include <QDebug>
#include <QFont>
CoreInterface::CoreInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreInterface)
{
    ui->setupUi(this);
    fontName.initFontName();
    fontLib.initFont();
    connect(ui->CommandLine,SIGNAL(textChanged(QString)),this,SLOT(CLITextChanged(QString)));
    connect(ui->ConfirmButton,SIGNAL(clicked()),this,SLOT(clickedOKButton()));
    connect(ui->CommandLine,SIGNAL(returnPressed()),this,SLOT(clickedOKButton()));
    connect(ui->StartButton,SIGNAL(clicked()),this,SLOT(clickedProcede()));
    connect(ui->ActionAboutQt,SIGNAL(triggered()),this,SLOT(aboutQtTriggered()));
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(exitActionTriggered()));
    connect(ui->sortButton,SIGNAL(clicked()),this,SLOT(sortButtonClicked()));
    connect(ui->TechnicalInfoAction,SIGNAL(triggered()),this,SLOT(TechnicalInfoTriggered()));
    connect(ui->AboutTATAction,SIGNAL(triggered()),this,SLOT(AboutTATTriggered()));
    applyFont(fontLib.targetFont);
}

CoreInterface::~CoreInterface()
{
    delete ui;
}
void CoreInterface::TechnicalInfoTriggered(){
    procBackend.objects.debug->show();
}
void CoreInterface::AboutTATTriggered(){
    abIp->show();
}
void CoreInterface::sortButtonClicked(){
    if(ui->NumeralSortSelect->isChecked()){
        procBackend.sortList("Numeral");
    }
    else if(ui->DictionalSortSelect->isChecked()){
        procBackend.sortList("Dictional");
    }
    else {
        QMessageBox::StandardButton warn = QMessageBox::warning(NULL,tr("Error!"),tr("No sorting method selected."),QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Yes);
    }
}
void CoreInterface::applyFont(QFont target){
    //Label
    ui->BeginLabel->setFont(target);
    ui->ClassLabel->setFont(target);
    ui->HeaderLabel->setFont(target);
    ui->SubScoreLabel->setFont(target);
    ui->NumeralSortExplainLabel->setFont(target);
    ui->DictionalSortExplainLabel->setFont(target);
    //Display
    ui->CoreDisplay->setFont(target);
    ui->previewDisplay->setFont(target);
    //Buttons
    ui->ClassSelectionMenu->setFont(target);
    ui->ConfirmButton->setFont(target);
    ui->sortButton->setFont(target);
    ui->StartButton->setFont(target);;
    ui->NumeralSortSelect->setFont(target);
    ui->DictionalSortSelect->setFont(target);
    //Actions
    ui->AboutTATAction->setFont(target);
    ui->ActionAboutQt->setFont(target);
    ui->ActionExit->setFont(target);
    //CommandLine
    ui->CommandLine->setFont(target);
    ui->HeaderEdit->setFont(target);
    ui->SubScoreItemsEdit->setFont(target);
    //Layout
    ui->SortLayout->setFont(target);
    ui->PreviewLayout->setFont(target);
    //tabs
    ui->EditorTabs->setFont(target);
}
void CoreInterface::addClass(int x){
    ui->ClassSelectionMenu->addItem(QString::number(x));
}
void CoreInterface::updatePreviewDisplay(QString target){
    ui->previewDisplay->setText(target);
}
void CoreInterface::CLITextChanged(const QString &target)
{
    procBackend.showSelectedStudent(target);
}
void CoreInterface::writeCoreDisplay(QString target){
    ui->CoreDisplay->setText(target);
}
void CoreInterface::writeCoreEditBar(QString target){
    ui->CommandLine->setText(target);
}
void CoreInterface::updateProgressBar(int cnt, int total){
    ui->progressBar->setMaximum(total);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(cnt);
}
void CoreInterface::clickedOKButton()
{
    QString command=ui->CommandLine->text().replace("，",",");
    procBackend.modifyStudentRes(command);
}
void CoreInterface::aboutQtTriggered()
{
    qDebug() << "[CoreInterface::about Qt]aboutQt triggered";
    QMessageBox aboutQt(NULL);
    aboutQt.aboutQt(NULL,"About Qt");
}
int CoreInterface::selectedClass()
{
    return ui->ClassSelectionMenu->currentText().toInt();
}
QString CoreInterface::chartHeader(){
    if(ui->HeaderEdit->text().isEmpty() && ui->SubScoreItemsEdit->text().isEmpty()){
        return QString("");
    }
    QString t;
    t.append(ui->HeaderEdit->text());
    t.append(",");
    t.append((ui->SubScoreItemsEdit->text())).replace("，",",");
    return t;
}
void CoreInterface::changeTab(int target){
    ui->EditorTabs->setCurrentIndex(target);
}
void CoreInterface::clickedProcede(){
    procBackend.loadSettings();
    procBackend.loadStudentInfo();
    procBackend.showSelectedStudent(QString(""));
    ui->EditorTabs->setCurrentIndex(1);
}
void CoreInterface::exitActionTriggered(){
    this->close();
}
