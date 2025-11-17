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

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* getCentralWidget() const {return centralWidget;}

private:
    QWidget *centralWidget;
    QStackedLayout *stack;
    //QGridLayout *gridLayout;

};
#endif
