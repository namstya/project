#include "mainwindow.h"
#include "ui_mainwindow.h"

std::matrix mat;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mat.new_game();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            str = "";
            str += '0' + mat.read(i,j);
            QTableWidgetItem *item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i,j,item);
            if(str != "0")
            item->setBackgroundColor(0xCCFF99);
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

// Генерация новой игры при нажатии кнопошки
void MainWindow::on_new_g_clicked() {
    mat.new_game();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            str="";
            str += '0' + mat.read(i,j);
            QTableWidgetItem *item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i,j,item);
            if(str != "0")
            item->setBackgroundColor(0xCCFF99);
        }
    }
}

// Если нажав на табличку
void MainWindow::on_table_cellClicked(int r, int c) {
    i = r;
    j = c;
}

// Жмяк на кнопку
void MainWindow::click_but(int n) {
    mat.add(i, j, n);
    str="";
    str += '0' + mat.read(i,j);
    QTableWidgetItem *item = new QTableWidgetItem(str);
    item->setTextAlignment(Qt::AlignCenter);
    ui->table->setItem(i,j,item);
    if(mat.win()) {
        QMessageBox msg;
        msg.setText("YOU WIN!");
        msg.exec();
    }
}

void MainWindow::on_b_1_clicked() {
    click_but(1);
}

void MainWindow::on_b_2_clicked() {
    click_but(2);
}

void MainWindow::on_b_3_clicked() {
    click_but(3);
}

void MainWindow::on_b_4_clicked() {
    click_but(4);
}

void MainWindow::on_b_5_clicked() {
    click_but(5);
}

void MainWindow::on_b_6_clicked() {
    click_but(6);
}

void MainWindow::on_b_7_clicked() {
    click_but(7);
}

void MainWindow::on_b_8_clicked() {
    click_but(8);
}

void MainWindow::on_b_9_clicked() {
    click_but(9);
}
