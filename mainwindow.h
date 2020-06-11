#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QString>
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_1_clicked();
    void on_b_2_clicked();
    void on_b_3_clicked();
    void on_b_4_clicked();
    void on_b_5_clicked();
    void on_b_6_clicked();
    void on_b_7_clicked();
    void on_b_8_clicked();
    void on_b_9_clicked();
    void on_table_cellClicked(int , int);
    void on_new_g_clicked();

private:
    Ui::MainWindow *ui;
    void click_but(int num);
    int i,j;
    QString str;
};
#endif // MAINWINDOW_H
