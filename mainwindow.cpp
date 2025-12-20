#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this))
{
    setCentralWidget(centralWidget);
    QStackedLayout *stack = new QStackedLayout(centralWidget);
    QWidget *home = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(home);
    home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QLabel *choiceGame = new QLabel("Choose game :", this);
        gridLayout->addWidget(choiceGame, 0, 0, 1, 2);

        xb1 = new QPushButton("Xenoblade DE", this);
        xb1->setFixedWidth(200);
        gridLayout->addWidget(xb1, 1, 0);
        connect(xb1, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb1";
            stack->setCurrentIndex(1);
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            GenerateDropTables->setEnabled(true);
        });

        xb2 = new QPushButton("Xenoblade 2", this);
        xb2->setFixedWidth(200);
        gridLayout->addWidget(xb2, 1, 1);
        connect(xb2, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb2";
            archiveName = "bf2";
            stack->setCurrentIndex(1);
            CreateBlade->setEnabled(true);
            ReadSave->setEnabled(true);
            DecompressIraSave->setEnabled(true);
        });

        xb3 = new QPushButton("Xenoblade 3", this);
        xb3->setFixedWidth(200);
        gridLayout->addWidget(xb3, 2, 0);
        connect(xb3, &QPushButton::clicked, this, [this, stack]()
        {
            archiveName = "bf3";
            stack->setCurrentIndex(1);
            commandGame = "xb3";
        });

        xbx = new QPushButton("Xenoblade X", this);
        xbx->setFixedWidth(200);
        gridLayout->addWidget(xbx, 2, 1);
        connect(xbx, &QPushButton::clicked, this, [this, stack]()
        {
            //archiveName = "sts";
            stack->setCurrentIndex(1);
            commandGame = "xbx";
        });
    stack->addWidget(home);

    QWidget *task = new QWidget();
    QGridLayout *taskGridLayout = new QGridLayout(task);
    task->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QLabel *currentSelectedGame = new QLabel("Current selected game : ", this);
        taskGridLayout->addWidget(currentSelectedGame, 0, 0);

        QLabel *choiceTask = new QLabel("Choose task :", this);
        taskGridLayout->addWidget(choiceTask, 0, 1, 1, 2);

        QLabel *archive = new QLabel("Archive", this);
        taskGridLayout->addWidget(archive, 1, 0);
            ExtractArchive = new QPushButton("Extract Archive", this);
            ExtractArchive->setFixedWidth(200);
            taskGridLayout->addWidget(ExtractArchive, 2, 0);
            connect(ExtractArchive, &QPushButton::clicked, this, [this]()
            {
                commandTask = "ExtractArchive";
                archivePathDialog();
            });

            ReplaceArchive = new QPushButton("Replace Archive", this);
            ReplaceArchive->setFixedWidth(200);
            taskGridLayout->addWidget(ReplaceArchive, 3, 0);

        QLabel *bdat = new QLabel("BDAT", this);
        taskGridLayout->addWidget(bdat, 1, 1);
            DecryptBdat = new QPushButton("Decrypt Bdat", this);
            DecryptBdat->setFixedWidth(200);
            taskGridLayout->addWidget(DecryptBdat, 2, 1);

            BdatCodeGen = new QPushButton("Bdat code generator", this);
            BdatCodeGen->setFixedWidth(200);
            taskGridLayout->addWidget(BdatCodeGen, 3, 1);

            Bdat2Html = new QPushButton("Bdat to HTML", this);
            Bdat2Html->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Html, 4, 1);

            Bdat2Json = new QPushButton("Bdat to JSON", this);
            Bdat2Json->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Json, 5, 1);

            Bdat2Psql = new QPushButton("Bdat to PSQL", this);
            Bdat2Psql->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Psql, 6, 1);

            GenerateData = new QPushButton("Generate Data", this);
            GenerateData->setFixedWidth(200);
            taskGridLayout->addWidget(GenerateData, 7, 1);

        QLabel *other = new QLabel("Other", this);
        taskGridLayout->addWidget(other, 1, 2);
            DescrambleScript = new QPushButton("Descramble Script", this);
            DescrambleScript->setFixedWidth(200);
            taskGridLayout->addWidget(DescrambleScript, 2, 2);

            ExtractWilay = new QPushButton("Extract Wilay", this);
            ExtractWilay->setFixedWidth(200);
            taskGridLayout->addWidget(ExtractWilay, 3, 2);

        QLabel *xb2only = new QLabel("Xenoblade 2 only", this);
        taskGridLayout->addWidget(xb2only, 1, 3);
            CreateBlade= new QPushButton("Create Blade", this);
            CreateBlade->setFixedWidth(200);
            taskGridLayout->addWidget(CreateBlade, 2, 3);
            CreateBlade->setEnabled(false);

            ReadSave = new QPushButton("Read Save", this);
            ReadSave->setFixedWidth(200);
            taskGridLayout->addWidget(ReadSave, 3, 3);
            ReadSave->setEnabled(false);

            DecompressIraSave  = new QPushButton("Decompress Ira Save", this);
            DecompressIraSave->setFixedWidth(200);
            taskGridLayout->addWidget(DecompressIraSave, 4, 3);
            DecompressIraSave->setEnabled(false);

        QLabel *xb1DEonly = new QLabel("Xenoblade DE only", this);
        taskGridLayout->addWidget(xb1DEonly, 1, 4);
            GenerateDropTables = new QPushButton("Generate Drop Tables", this);
            GenerateDropTables->setFixedWidth(200);
            taskGridLayout->addWidget(GenerateDropTables, 2, 4);
            GenerateDropTables->setEnabled(false);

        /*
        QString commandUser;
        QString commandGame;
        QString commandTask;
        QString commandArchive;
        QString commandBDAT;
        QString commandInput;
        QString commandOutput;
        */

    stack->addWidget(task);

    stack->setCurrentIndex(0);
}

void MainWindow::archivePathDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Extract Archive");
    dialog.setMinimumWidth(400);

    QLabel *arhlabel = new QLabel("ARH path:");
    QLineEdit *arhPathEdit = new QLineEdit();

    QLabel *ardlabel = new QLabel("ARD path:");
    QLineEdit *ardPathEdit = new QLineEdit();

    QPushButton *archiveBrowse = new QPushButton("Set archive (.ard && .arh) location");
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    QGridLayout *gridDialog = new QGridLayout(&dialog);
        gridDialog->addWidget(arhlabel, 0, 0);
        gridDialog->addWidget(arhPathEdit, 0, 1, 1, 4);

        gridDialog->addWidget(ardlabel, 1, 0);
        gridDialog->addWidget(ardPathEdit, 1, 1, 1, 4);

        gridDialog->addWidget(archiveBrowse, 2, 1, 1, 4);
        gridDialog->addWidget(okButton, 3, 3);
        gridDialog->addWidget(cancelButton, 3, 4);

    connect(archiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        QString folder = QFileDialog::getExistingDirectory(&dialog, "Choose the folder where the archives are located");
        if (QDir(folder).isEmpty()) { QMessageBox::warning(&dialog, "Missing files", "The folder is empty"); }
        else if (QFileInfo::exists(folder + "/"+archiveName+".arh") && QFileInfo::exists(folder + "/"+archiveName+".ard"))
        {
            arhPathEdit->setText(folder + "/"+archiveName+".arh");
            ardPathEdit->setText(folder + "/"+archiveName+".ard");
        }
        else if (!QFileInfo::exists(folder + "/"+archiveName+".arh") && !QFileInfo::exists(folder + "/"+archiveName+".ard"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".arh & "+archiveName+".ard"); }
        else if (!QFileInfo::exists(folder + "/"+archiveName+".arh"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".arh"); }
        else if (!QFileInfo::exists(folder + "/"+archiveName+".ard"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".ard"); }
    });

    if (dialog.exec() == QDialog::Accepted)
    {
        QString chosenPath = arhPathEdit->text();
        if (!chosenPath.isEmpty())
        {
            // WIP
        }
    }
}

MainWindow::~MainWindow(){}
