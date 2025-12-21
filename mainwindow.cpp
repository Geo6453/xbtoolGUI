#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this))
{
    setCentralWidget(centralWidget);
    QStackedLayout *stack = new QStackedLayout(centralWidget); //stock all the menus
    QWidget *home = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(home);
    home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QLabel *choiceGame = new QLabel("Choose game :", this);
        gridLayout->addWidget(choiceGame, 0, 0, 1, 2);

        xb1 = new QPushButton("Xenoblade DE", this);
        xb1->setMinimumHeight(100);
        gridLayout->addWidget(xb1, 1, 0);
        connect(xb1, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = " -g xb1";
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            GenerateDropTables->setEnabled(true);
            stack->setCurrentIndex(1);
        });

        xb2 = new QPushButton("Xenoblade 2", this);
        xb2->setMinimumHeight(100);
        gridLayout->addWidget(xb2, 1, 1);
        connect(xb2, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = " -g xb2";
            archiveName = "bf2";
            CreateBlade->setEnabled(true);
            ReadSave->setEnabled(true);
            DecompressIraSave->setEnabled(true);
            stack->setCurrentIndex(1);
        });

        xb3 = new QPushButton("Xenoblade 3", this);
        xb3->setMinimumHeight(100);
        gridLayout->addWidget(xb3, 2, 0);
        connect(xb3, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = " -g xb3";
            archiveName = "bf3";
            stack->setCurrentIndex(1);
        });

        xbx = new QPushButton("Xenoblade X", this);
        xbx->setMinimumHeight(100);
        gridLayout->addWidget(xbx, 2, 1);
        connect(xbx, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = " -g xbx";
            //archiveName = "sts";
            stack->setCurrentIndex(1);
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
            ExtractArchive->setMinimumWidth(200);
            taskGridLayout->addWidget(ExtractArchive, 2, 0);
            connect(ExtractArchive, &QPushButton::clicked, this, [this]()
            {
                commandTask = " -t ExtractArchive";
                archivePathDialog();
            });

            ReplaceArchive = new QPushButton("Replace Archive", this);
            ReplaceArchive->setMinimumWidth(200);
            taskGridLayout->addWidget(ReplaceArchive, 3, 0);

        QLabel *bdat = new QLabel("BDAT", this);
        taskGridLayout->addWidget(bdat, 1, 1);
            DecryptBdat = new QPushButton("Decrypt Bdat", this);
            DecryptBdat->setMinimumWidth(200);
            taskGridLayout->addWidget(DecryptBdat, 2, 1);

            BdatCodeGen = new QPushButton("Bdat code generator", this);
            BdatCodeGen->setMinimumWidth(200);
            taskGridLayout->addWidget(BdatCodeGen, 3, 1);

            Bdat2Html = new QPushButton("Bdat to HTML", this);
            Bdat2Html->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Html, 4, 1);

            Bdat2Json = new QPushButton("Bdat to JSON", this);
            Bdat2Json->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Json, 5, 1);

            Bdat2Psql = new QPushButton("Bdat to PSQL", this);
            Bdat2Psql->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Psql, 6, 1);

            GenerateData = new QPushButton("Generate Data", this);
            GenerateData->setMinimumWidth(200);
            taskGridLayout->addWidget(GenerateData, 7, 1);

        QLabel *other = new QLabel("Other", this);
        taskGridLayout->addWidget(other, 1, 2);
            DescrambleScript = new QPushButton("Descramble Script", this);
            DescrambleScript->setMinimumWidth(200);
            taskGridLayout->addWidget(DescrambleScript, 2, 2);

            ExtractWilay = new QPushButton("Extract Wilay", this);
            ExtractWilay->setMinimumWidth(200);
            taskGridLayout->addWidget(ExtractWilay, 3, 2);

        QLabel *xb2only = new QLabel("Xenoblade 2 only", this);
        taskGridLayout->addWidget(xb2only, 1, 3);
            CreateBlade= new QPushButton("Create Blade", this);
            CreateBlade->setMinimumWidth(200);
            taskGridLayout->addWidget(CreateBlade, 2, 3);
            CreateBlade->setEnabled(false);

            ReadSave = new QPushButton("Read Save", this);
            ReadSave->setMinimumWidth(200);
            taskGridLayout->addWidget(ReadSave, 3, 3);
            ReadSave->setEnabled(false);

            DecompressIraSave  = new QPushButton("Decompress Ira Save", this);
            DecompressIraSave->setMinimumWidth(200);
            taskGridLayout->addWidget(DecompressIraSave, 4, 3);
            DecompressIraSave->setEnabled(false);

        QLabel *xb1DEonly = new QLabel("Xenoblade DE only", this);
        taskGridLayout->addWidget(xb1DEonly, 1, 4);
            GenerateDropTables = new QPushButton("Generate Drop Tables", this);
            GenerateDropTables->setMinimumWidth(200);
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

    qDebug() << "Test qDebug";
}

void MainWindow::archivePathDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Extract Archive");
    dialog.setMinimumWidth(400);

    QLabel *arhlabel = new QLabel("ARH path:");
    QLabel *ardlabel = new QLabel("ARD path:");
    QLabel *outputArchiveLabel = new QLabel("Output directory :");

    QLineEdit *arhPathEdit = new QLineEdit();
    QLineEdit *ardPathEdit = new QLineEdit();
        QPushButton *inputArchiveBrowse = new QPushButton("Set archive (.ard && .arh) location");
    QLineEdit *outputArchiveEdit = new QLineEdit();
        QPushButton *outputArchiveBrowse = new QPushButton ("Set output directory");

    arhPathEdit->setReadOnly(true);
    ardPathEdit->setReadOnly(true);
    outputArchiveEdit->setReadOnly(true);

    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    QGridLayout *gridDialog = new QGridLayout(&dialog);
        gridDialog->addWidget(arhlabel,             0, 0);
        gridDialog->addWidget(ardlabel,             1, 0);
        gridDialog->addWidget(outputArchiveLabel,   3, 0);

        gridDialog->addWidget(arhPathEdit,          0, 1, 1, 4);
        gridDialog->addWidget(ardPathEdit,          1, 1, 1, 4);
        gridDialog->addWidget(inputArchiveBrowse,        2, 1, 1, 4);
        gridDialog->addWidget(outputArchiveEdit,    3, 1, 1, 4);
        gridDialog->addWidget(outputArchiveBrowse,  4, 1, 1, 4);

        gridDialog->addWidget(okButton,             5, 3);
        gridDialog->addWidget(cancelButton,         5, 4);

    connect(inputArchiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        QString inputFolder = QFileDialog::getExistingDirectory
        (
            &dialog,
            "Choose the folder where the archives are located",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation) //Open the dialog at the user's folder
        );
        //Errors management
        if (QDir(inputFolder).isEmpty()) { QMessageBox::warning(&dialog, "Missing files", "The folder is empty"); }
        else if (!QFileInfo::exists(inputFolder + "/"+archiveName+".arh") && !QFileInfo::exists(inputFolder + "/"+archiveName+".ard"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".arh & "+archiveName+".ard"); }
        else if (!QFileInfo::exists(inputFolder + "/"+archiveName+".arh"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".arh"); }
        else if (!QFileInfo::exists(inputFolder + "/"+archiveName+".ard"))
            { QMessageBox::warning(&dialog, "Missing files", "Missing "+archiveName+".ard"); }
        else if (QFileInfo::exists(inputFolder + "/"+archiveName+".arh") && QFileInfo::exists(inputFolder + "/"+archiveName+".ard"))
        {
            arhPathEdit->setText(inputFolder + "/"+archiveName+".arh");
            ardPathEdit->setText(inputFolder + "/"+archiveName+".ard");
        }
    });

    connect(outputArchiveBrowse, &QPushButton::clicked, &dialog, [&]()
    {
        QString outputFolder = QFileDialog::getExistingDirectory
        (
            &dialog,
            "Choose the directory for the archive's dump",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation) //Open the dialog at the user's folder
        );

        if (QDir(outputFolder).isEmpty()) { outputArchiveEdit->setText(outputFolder); }
        if (!QDir(outputFolder).isEmpty() && QMessageBox::question
        (
            &dialog, "Advice",
            "The folder isn't empty, are you sure to dump your archive here?",
            QMessageBox::Yes | QMessageBox::No
        ) == QMessageBox::Yes) { outputArchiveEdit->setText(outputFolder); }
        else { return; }
    });

    connect(okButton,     &QPushButton::clicked, &dialog, &QDialog::accept);

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        QString commandArchive = " -a \"" + arhPathEdit->text() + "\" \"" + ardPathEdit->text() + "\"";
        QString commandOutput = " -o \"" + outputArchiveEdit->text() + "\"";
        QString commandUser =  "xbtool.exe" + commandGame + commandTask + commandArchive + commandOutput;
        qDebug().noquote() << commandUser;
    }
}
MainWindow::~MainWindow(){}
