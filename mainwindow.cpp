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

        QPushButton *xc1 = new QPushButton("Xenoblade DE", this);
        xc1->setFixedWidth(200);
        gridLayout->addWidget(xc1, 1, 0);
        connect(xc1, &QPushButton::clicked, this, [this, stack]()
                {stack->setCurrentIndex(1);});

        QPushButton *xc2 = new QPushButton("Xenoblade 2", this);
        xc2->setFixedWidth(200);
        gridLayout->addWidget(xc2, 1, 1);
        connect(xc2, &QPushButton::clicked, this, [this, stack]()
                {stack->setCurrentIndex(1);});

        QPushButton *xc3 = new QPushButton("Xenoblade 3", this);
        xc3->setFixedWidth(200);
        gridLayout->addWidget(xc3, 2, 0);
        connect(xc3, &QPushButton::clicked, this, [this, stack]()
                {stack->setCurrentIndex(1);});

        QPushButton *xcx = new QPushButton("Xenoblade X", this);
        xcx->setFixedWidth(200);
        gridLayout->addWidget(xcx, 2, 1);
        connect(xcx, &QPushButton::clicked, this, [this, stack]()
                {stack->setCurrentIndex(1);});
    stack->addWidget(home);

    QWidget *task = new QWidget();
    QGridLayout *taskGridLayout = new QGridLayout(task);
    task->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QLabel *choiceTask = new QLabel("Choose task :", this);
        taskGridLayout->addWidget(choiceTask, 0, 0, 1, 2);

        QLabel *archive = new QLabel("Archive", this);
        taskGridLayout->addWidget(archive, 1, 0);
            QPushButton *ExtractArchive = new QPushButton("Extract Archive", this);
            ExtractArchive->setFixedWidth(200);
            taskGridLayout->addWidget(ExtractArchive, 2, 0);

            QPushButton *ReplaceArchive = new QPushButton("Replace Archive", this);
            ReplaceArchive->setFixedWidth(200);
            taskGridLayout->addWidget(ReplaceArchive, 3, 0);

        QLabel *bdat = new QLabel("BDAT", this);
        taskGridLayout->addWidget(bdat, 1, 1);
            QPushButton *DecryptBdat = new QPushButton("Decrypt Bdat", this);
            DecryptBdat->setFixedWidth(200);
            taskGridLayout->addWidget(DecryptBdat, 2, 1);

            QPushButton *BdatCodeGen = new QPushButton("Bdat code generator", this);
            BdatCodeGen->setFixedWidth(200);
            taskGridLayout->addWidget(BdatCodeGen, 3, 1);

            QPushButton *Bdat2Html = new QPushButton("Bdat to HTML", this);
            Bdat2Html->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Html, 4, 1);

            QPushButton *Bdat2Json = new QPushButton("Bdat to JSON", this);
            Bdat2Json->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Json, 5, 1);

            QPushButton *Bdat2Psql = new QPushButton("Bdat to PSQL", this);
            Bdat2Psql->setFixedWidth(200);
            taskGridLayout->addWidget(Bdat2Psql, 6, 1);

            QPushButton *GenerateData = new QPushButton("Generate Data", this);
            GenerateData->setFixedWidth(200);
            taskGridLayout->addWidget(GenerateData, 7, 1);

        QLabel *other = new QLabel("Other", this);
        taskGridLayout->addWidget(other, 1, 2);
            QPushButton *DescrambleScript = new QPushButton("Descramble Script", this);
            DescrambleScript->setFixedWidth(200);
            taskGridLayout->addWidget(DescrambleScript, 2, 2);

            QPushButton *ExtractWilay = new QPushButton("Extract Wilay", this);
            ExtractWilay->setFixedWidth(200);
            taskGridLayout->addWidget(ExtractWilay, 3, 2);

        QLabel *xb2only = new QLabel("Xenoblade 2 only", this);
        taskGridLayout->addWidget(xb2only, 1, 3);
            QPushButton *CreateBlade= new QPushButton("Create Blade", this);
            CreateBlade->setFixedWidth(200);
            taskGridLayout->addWidget(CreateBlade, 2, 3);

            QPushButton *ReadSave = new QPushButton("Read Save", this);
            ReadSave->setFixedWidth(200);
            taskGridLayout->addWidget(ReadSave, 3, 3);

            QPushButton *DecompressIraSave  = new QPushButton("Decompress Ira Save", this);
            DecompressIraSave->setFixedWidth(200);
            taskGridLayout->addWidget(DecompressIraSave, 4, 3);

        QLabel *xc1DEonly = new QLabel("Xenoblade DE only", this);
        taskGridLayout->addWidget(xc1DEonly, 1, 4);
            QPushButton *GenerateDropTables = new QPushButton("Generate Drop Tables", this);
            GenerateDropTables->setFixedWidth(200);
            taskGridLayout->addWidget(GenerateDropTables, 2, 4);
            GenerateDropTables->setEnabled(false);

        //si xenoblade 2 n'est pas choisi alors griser boutons tasks suivants : CreateBlade | ReadSave | DecompressIraSave
        // et pour XC1DE :  GenerateDropTables
            //->setEnabled(false);


    stack->addWidget(task);

    stack->setCurrentIndex(1);
}
MainWindow::~MainWindow(){}
