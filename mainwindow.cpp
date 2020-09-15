#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <vector>
#include <QMessageBox>
#include <iostream>
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string input_1 = ui->textEdit->toPlainText().toStdString();
    int width_1 = ui->lineEdit->text().toInt();
    int height_1 = ui->lineEdit_2->text().toInt();
    Matrix m1 = Matrix(height_1, width_1,input_1);

    std::string input_2 = ui->textEdit_2->toPlainText().toStdString();
    int width_2 = ui->lineEdit_3->text().toInt();
    int height_2 = ui->lineEdit_4->text().toInt();
    Matrix m2 = Matrix(height_2, width_2, input_2);

    Matrix* solution = NULL;
    solution = m1.add(m2);
    if(ui->add_but->isChecked()) {
        solution = m1.add(m2);
    }
    else if (ui->sub_but->isChecked()) {
        solution = m1.sub(m2);
    }
    else if (ui->mult_but->isChecked()) {
        solution = m1.mult(m2);       
    }
    else if (ui->scale_but->isChecked()) {
        solution = m1.scale(ui->lineEdit_5->text().toInt());
    }
    else {
        return;
    }

    if(solution == NULL) {
        QMessageBox::warning(this,"Bad Input","Matricies Sizes are not valid");
    }
    else {
        std::string check = solution->stringify();
        ui->textBrowser->setPlainText(QString::fromStdString(check));
    }
}




