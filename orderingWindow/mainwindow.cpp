/**
 * @brief This is mainwindow class, use it to show mainwindow and set up buttons
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "restaurant.h"
#include "menu.h"
#include "dish.h"
#include "dialog.h"
#include "checkoutwindow.h"
#include "Table.h"


/**
 * @brief Constructor for MainWindow class
 * @param q
 * @param parent
 */
MainWindow::MainWindow(std::shared_ptr<OrderQueue> q, QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    q2 = q;
}

/**
 * @brief Destructor for MainWindow class
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief Send a signal while clicking table 1 order button
 */
void MainWindow::on_pushButton_25_clicked()
{
    emit order1();
}


/**
 * @brief Send a signal while clicking table 1 hurry button
 */
void MainWindow::on_pushButton_26_clicked()
{
    emit hurry1();
}


/**
 * @brief Send a signal while clicking table 1 NeedHelp button
 */
void MainWindow::on_pushButton_3_clicked()
{
    emit NeedHelp1();
}


/**
 * @brief Send a signal while clicking table 1 CheckOut button
 */
void MainWindow::on_pushButton_28_clicked()
{
   emit popupWindow1();
}


/**
 * @brief Send a signal while clicking table 2 order button
 */
void MainWindow::on_pushButton_5_clicked()
{
    emit order2();
}

/**
 * @brief Send a signal while clicking table 2 hurry button
 */
void MainWindow::on_pushButton_6_clicked()
{
    emit hurry2();

}

/**
 * @brief Send a signal while clicking table 2 NeedHelp button
 */
void MainWindow::on_pushButton_7_clicked()
{
    emit NeedHelp2();
}

/**
 * @brief Send a signal while clicking table 2 CheckOut button
 */
void MainWindow::on_pushButton_8_clicked()
{
    emit popupWindow2();
}

// table 3 order button
void MainWindow::on_pushButton_9_clicked()
{
    emit order3();
}

// table 3 hurry button
void MainWindow::on_pushButton_10_clicked()
{
    emit hurry3();
}

// table 3 NeedHelp button
void MainWindow::on_pushButton_11_clicked()
{
    emit NeedHelp3();
}


//table 3 CheckOut button
void MainWindow::on_pushButton_12_clicked()
{
    emit popupWindow3();
}

// table 4 order button
void MainWindow::on_pushButton_13_clicked()
{
    emit order4();
}

// table 4 hurry button
void MainWindow::on_pushButton_14_clicked()
{
    emit hurry4();
}

// table 4 NeedHelp button
void MainWindow::on_pushButton_15_clicked()
{
    emit NeedHelp4();
}

// table 4 CheckOut button
void MainWindow::on_pushButton_16_clicked()
{
    emit popupWindow4();
}


// table 5 order button
void MainWindow::on_pushButton_17_clicked()
{
    emit order5();
}

// table 5 hurry button
void MainWindow::on_pushButton_18_clicked()
{
    emit hurry5();
}

// table 5 NeedHelp button
void MainWindow::on_pushButton_19_clicked()
{
    emit NeedHelp5();
}

// table 5 CheckOut button
void MainWindow::on_pushButton_20_clicked()
{
    emit popupWindow5();
}


// table 6 order button
void MainWindow::on_pushButton_21_clicked()
{
    emit order6();
}

// table 6 hurry button
void MainWindow::on_pushButton_22_clicked()
{
    emit hurry6();
}

// table 6 NeedHelp button
void MainWindow::on_pushButton_23_clicked()
{
     emit NeedHelp6();
}

// table 6 CheckOut butto
void MainWindow::on_pushButton_24_clicked()
{
    emit popupWindow6();
}

