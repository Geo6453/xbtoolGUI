#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <Qt>
#include <QStackedLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* getCentralWidget() const {return centralWidget;}
    QString commandUser;
    QString commandGame;
    QString commandTask;
    QString archiveName;
    QString commandArchive;
    QString commandBDAT;
    QString commandInput;
    QString commandOutput;

private:
    QWidget *centralWidget;
    QStackedLayout *stack;
    void archivePathDialog();
    //QGridLayout *gridLayout;
    QPushButton *xb1;
    QPushButton *xb2;
    QPushButton *xb3;
    QPushButton *xbx;
    QPushButton *ExtractArchive;
    QPushButton *ReplaceArchive;
    QPushButton *DecryptBdat;
    QPushButton *BdatCodeGen;
    QPushButton *Bdat2Html;
    QPushButton *Bdat2Json;
    QPushButton *Bdat2Psql;
    QPushButton *GenerateData;
    QPushButton *DescrambleScript;
    QPushButton *ExtractWilay;
    QPushButton *CreateBlade;
    QPushButton *ReadSave;
    QPushButton *DecompressIraSave;
    QPushButton *GenerateDropTables;

};
#endif
