#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this))
{
    bold.setBold(true);
    italic.setItalic(true);
    bolditalic.setBold(true);
    bolditalic.setItalic(true);

    setCentralWidget(centralWidget);
    QStackedLayout *stack = new QStackedLayout(centralWidget); //stock all the menus
    QWidget *home = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(home);
    home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QLabel *choiceGame = new QLabel("Choose game :", this);
        gridLayout->addWidget(choiceGame, 0, 0, 1, 2);

        xb1 = new QPushButton("Xenoblade 1", this);
        xb1->setMinimumHeight(60);
        gridLayout->addWidget(xb1, 1, 0);
        connect(xb1, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb1";
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            GenerateDropTables->setEnabled(true);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb1de = new QPushButton("Xenoblade 1 DE", this);
        xb1de->setMinimumHeight(60);
        gridLayout->addWidget(xb1de, 1, 1);
        connect(xb1de, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb1de";
            ExtractArchive->setEnabled(false);
            ReplaceArchive->setEnabled(false);
            GenerateDropTables->setEnabled(true);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb2 = new QPushButton("Xenoblade 2", this);
        xb2->setMinimumHeight(60);
        gridLayout->addWidget(xb2, 2, 0);
        connect(xb2, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb2";
            archiveName = "bf2";
            CreateBlade->setEnabled(true);
            ReadSave->setEnabled(true);
            DecompressIraSave->setEnabled(true);
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xb3 = new QPushButton("Xenoblade 3", this);
        xb3->setMinimumHeight(60);
        gridLayout->addWidget(xb3, 2, 1);
        connect(xb3, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xb3";
            archiveName = "bf3";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xbx = new QPushButton("Xenoblade X", this);
        xbx->setMinimumHeight(60);
        gridLayout->addWidget(xbx, 3, 0);
        connect(xbx, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xbx";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });

        xbxde = new QPushButton("Xenoblade X DE", this);
        xbxde->setMinimumHeight(60);
        gridLayout->addWidget(xbxde, 3, 1);
        connect(xbxde, &QPushButton::clicked, this, [this, stack]()
        {
            commandGame = "xbxde";
            archiveName = "sts";
            stack->setCurrentIndex(1);
            CSGedit->setText("Current selected game : " + commandGame);
        });
    stack->addWidget(home);

    QWidget *task = new QWidget();
    QGridLayout *taskGridLayout = new QGridLayout(task);
    task->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        // CSG mean Current Selected Game
        CSGedit = new QLabel("Current selected game : ...", this);
            taskGridLayout->addWidget(CSGedit, 0, 0);

        QPushButton *backToGameList = new QPushButton("Back");
            backToGameList->setMaximumWidth(60);
            connect(backToGameList, &QPushButton::clicked, this, [this, stack]()
            {
                commandGame = "";
                archiveName = "";
                stack->setCurrentIndex(0);
            });
            taskGridLayout->addWidget(backToGameList, 0, 1);

        QLabel *choiceTask = new QLabel("Choose task :", this);
            choiceTask->setFont(bold);
            taskGridLayout->addWidget(choiceTask, 1, 0);

        QLabel *archive = new QLabel("Archive", this);
            taskGridLayout->addWidget(archive, 2, 0);
            ExtractArchive = new QPushButton("Extract Archive", this);
            ExtractArchive->setMinimumWidth(200);
            taskGridLayout->addWidget(ExtractArchive, 3, 0);
            connect(ExtractArchive, &QPushButton::clicked, this, [this]()
            {
                commandTask = "ExtractArchive";
                archivePathDialog();
            });

            ReplaceArchive = new QPushButton("Replace Archive", this);
            ReplaceArchive->setMinimumWidth(200);
            taskGridLayout->addWidget(ReplaceArchive, 4, 0);

        QLabel *bdat = new QLabel("BDAT", this);
            taskGridLayout->addWidget(bdat, 2, 1);
            DecryptBdat = new QPushButton("Decrypt Bdat", this);
            DecryptBdat->setMinimumWidth(200);
            taskGridLayout->addWidget(DecryptBdat, 3, 1);

            BdatCodeGen = new QPushButton("Bdat code generator", this);
            BdatCodeGen->setMinimumWidth(200);
            taskGridLayout->addWidget(BdatCodeGen, 4, 1);

            Bdat2Html = new QPushButton("Bdat to HTML", this);
            Bdat2Html->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Html, 5, 1);

            Bdat2Json = new QPushButton("Bdat to JSON", this);
            Bdat2Json->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Json, 6, 1);

            Bdat2Psql = new QPushButton("Bdat to PSQL", this);
            Bdat2Psql->setMinimumWidth(200);
            taskGridLayout->addWidget(Bdat2Psql, 7, 1);

            GenerateData = new QPushButton("Generate Data", this);
            GenerateData->setMinimumWidth(200);
            taskGridLayout->addWidget(GenerateData, 8, 1);

        QLabel *other = new QLabel("Other", this);
            taskGridLayout->addWidget(other, 2, 2);
            DescrambleScript = new QPushButton("Descramble Script", this);
            DescrambleScript->setMinimumWidth(200);
            taskGridLayout->addWidget(DescrambleScript, 3, 2);

            ExtractWilay = new QPushButton("Extract Wilay", this);
            ExtractWilay->setMinimumWidth(200);
            taskGridLayout->addWidget(ExtractWilay, 4, 2);

        QLabel *xb2only = new QLabel("Xenoblade 2 only", this);
            taskGridLayout->addWidget(xb2only, 2, 3);
            CreateBlade= new QPushButton("Create Blade", this);
            CreateBlade->setMinimumWidth(200);
            taskGridLayout->addWidget(CreateBlade, 3, 3);
            CreateBlade->setEnabled(false);

            ReadSave = new QPushButton("Read Save", this);
            ReadSave->setMinimumWidth(200);
            taskGridLayout->addWidget(ReadSave, 4, 3);
            ReadSave->setEnabled(false);

            DecompressIraSave  = new QPushButton("Decompress Ira Save", this);
            DecompressIraSave->setMinimumWidth(200);
            taskGridLayout->addWidget(DecompressIraSave, 5, 3);
            DecompressIraSave->setEnabled(false);

        QLabel *xb1DEonly = new QLabel("Xenoblade DE only", this);
            taskGridLayout->addWidget(xb1DEonly, 2, 4);
            GenerateDropTables = new QPushButton("Generate Drop Tables", this);
            GenerateDropTables->setMinimumWidth(200);
            taskGridLayout->addWidget(GenerateDropTables, 3, 4);
            GenerateDropTables->setEnabled(false);

        archive->setFont(italic);
        bdat->setFont(italic);
        other->setFont(italic);
        xb2only->setFont(italic);
        xb1DEonly->setFont(italic);

    stack->addWidget(task);
    stack->setCurrentIndex(0);
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
        gridDialog->addWidget(arhlabel,            0, 0);
        gridDialog->addWidget(ardlabel,            1, 0);
        gridDialog->addWidget(outputArchiveLabel,  3, 0);

        gridDialog->addWidget(arhPathEdit,         0, 1, 1, 4);
        gridDialog->addWidget(ardPathEdit,         1, 1, 1, 4);
        gridDialog->addWidget(inputArchiveBrowse,  2, 1, 1, 4);
        gridDialog->addWidget(outputArchiveEdit,   3, 1, 1, 4);
        gridDialog->addWidget(outputArchiveBrowse, 4, 1, 1, 4);

        gridDialog->addWidget(okButton,            5, 3);
        gridDialog->addWidget(cancelButton,        5, 4);

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
        if (!QFileInfo::exists(programOGpath))
        {
            QMessageBox::critical(this, "Error", "XbTool.exe not found.");
            return;
        }
        else { qDebug() << "Launching..."; }

        commandUser.clear();
        commandUser << "-g" << commandGame
                    << "-t" << commandTask
                    << "-a" << arhPathEdit->text()
                            << ardPathEdit->text()
                    << "-o" << outputArchiveEdit->text(); //CLI command parsing is different for user and QProcess
        qDebug() << commandUser;
        qDebug().noquote() << commandUser;

        QDialog *progressDialog = new QDialog(this);
            progressDialog->setWindowTitle("XbTool - Extracting");
            progressDialog->setMinimumSize(500, 100);

            QVBoxLayout *layout = new QVBoxLayout(progressDialog);

            QProgressBar *progressBar = new QProgressBar(progressDialog);
                progressBar->setRange(0, 100);
                progressBar->setValue(0);
                layout->addWidget(progressBar);

            QProcess *process = new QProcess(progressDialog);
                QString stdoutBuffer;
                connect(process, &QProcess::readyReadStandardOutput, progressDialog, [=]() mutable
                {
                    stdoutBuffer += QString::fromLocal8Bit(process->readAllStandardOutput());
                    static QRegularExpression re("/.*?(\\d{1,3}(?:[.,]\\d+)?)\\s*%");
                    QRegularExpressionMatchIterator it = re.globalMatch(stdoutBuffer);
                    double lastValue = -1.0;
                    while (it.hasNext())
                    {
                        QRegularExpressionMatch m = it.next();
                        QString num = m.captured(1);
                        num.replace(',', '.');
                        lastValue = num.toDouble();
                    }
                    if (lastValue >= 0.0 && lastValue <= 100.0)
                    {
                        progressBar->setValue(qRound(lastValue));
                        progressBar->setFormat(QString::number(lastValue, 'f', 1) + " %");
                    }
                });

            QPushButton *closeBtn = new QPushButton("Close", progressDialog);
                closeBtn->setEnabled(false);
                layout->addWidget(closeBtn);
                connect(closeBtn, &QPushButton::clicked, progressDialog, &QDialog::accept);

            QPushButton *cancelBtn = new QPushButton("Cancel", progressDialog);
                layout->addWidget(cancelBtn);
                connect(cancelBtn, &QPushButton::clicked, progressDialog, [=]()
                {
                    if (process->state() == QProcess::Running) process->kill();
                    cancelBtn->setEnabled(false);
                    closeBtn->setEnabled(true);
                });

            connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), progressDialog, [=](int, QProcess::ExitStatus)
            {
                progressBar->setValue(100);
                progressBar->setFormat("100 %");
                cancelBtn->setEnabled(false);
                closeBtn->setEnabled(true);
            });

            process->start(programOGpath, commandUser);

        progressDialog->show();
    }
}

MainWindow::~MainWindow(){}
