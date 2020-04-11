#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myarray.h"
#include <QDebug>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    char* text = QStringToCharArray(ui->lineEdit->text());
    MyString ms(text);
    list.append(ms);
    ui->listWidget->clear();
    ui->lineEdit->clear();
    list >> ui->listWidget;
}

void MainWindow::on_pushButton_2_clicked()
{
    MyString min = list.min();
    ui->lineEdit_2->setText(QString::fromStdString(min));
}

void MainWindow::on_pushButton_3_clicked()
{
    list.sortD();
    ui->listWidget->clear();
    list >> ui->listWidget;
}

void MainWindow::on_pushButton_4_clicked()
{
    list.sortI();
    ui->listWidget->clear();
    list >> ui->listWidget;
}

char *MainWindow::QStringToCharArray(QString text)
{
    return text.toLocal8Bit().data();
}
