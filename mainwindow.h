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
#include <QProcess>
#include <QProgressBar>
#include <QPlainTextEdit>
#include <QRegularExpression>
#include <QScrollBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* getCentralWidget() const {return centralWidget;}
    QStringList commandUser;
    QString commandGame;
    QString commandTask;
    QString archiveName;
    QString commandBDAT;
    QString commandInput;
    QString programOGpath = QDir("../../../XbTool").absoluteFilePath("XbTool.exe");

private:
    QWidget *centralWidget;
    QStackedLayout *stack;
    void archivePathDialog();
    QPushButton *xb1;
    QPushButton *xb1de;
    QPushButton *xb2;
    QPushButton *xb3;
    QPushButton *xbx;
    QPushButton *xbxde;
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
