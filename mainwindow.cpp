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
    char *text = QStringToCharArray(ui->lineEdit->text());
    MyString ms(text);
    list.append(ms); //тут крашається прога коли додаю елемент і перевищую копасіті. тоді говорить що подвійде видалення пам'яті
    ui->listWidget->clear();
    ui->lineEdit->clear();
    for(unsigned i = 0; i < list.getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString((std::string)list.getElement(i))); //отут і викинає проблема.
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    /*MyString min = list.min();
    ui->lineEdit_2->setText(QString::fromStdString((std::string)min));*/

}

void MainWindow::on_pushButton_3_clicked()
{
    /*list.sortD();
    ui->listWidget->clear();*/

}

void MainWindow::on_pushButton_4_clicked()
{
    /*list.sortI();
    ui->listWidget->clear();*/

}

char *MainWindow::QStringToCharArray(QString text)
{
    return text.toLocal8Bit().data();
}
