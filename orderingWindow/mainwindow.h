/**
 * @brief This is head file of mainwindow.cpp file.
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLabel>
#include "orderqueue.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void order1();
    void hurry1();
    void NeedHelp1();

    void order2();
    void hurry2();
    void NeedHelp2();
    //void hurryDisplay();

    void order3();
    void hurry3();
    void NeedHelp3();

    void order4();
    void hurry4();
    void NeedHelp4();

    void order5();
    void hurry5();
    void NeedHelp5();

    void order6();
    void hurry6();
    void NeedHelp6();

    void popupWindow1();
    void popupWindow2();
    void popupWindow3();
    void popupWindow4();
    void popupWindow5();
    void popupWindow6();

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(std::shared_ptr<OrderQueue> q, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *needhelp_display;
    std::shared_ptr<OrderQueue> q2;

};
#endif // MAINWINDOW_H
