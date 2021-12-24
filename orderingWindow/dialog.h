/**
 * @brief This is head file of dialog.cpp file.
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "orderqueue.h"
#include "dish.h"
#include "order.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

signals:
    void display();
    void sendMoney(double);

public:

    explicit Dialog(std::shared_ptr<OrderQueue> q, Dish* d[],QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_2_clicked();
    void receiveData();
    void receiveData2();
    void receiveData3();
    void receiveData4();
    void receiveData5();
    void receiveData6();

private:
    Ui::Dialog *ui;
    std::shared_ptr<OrderQueue> q_ptr;
    OrderQueue q;
    Dish chic_taco=Dish("Chicken Tacos");
    Dish chicken=Dish("Chicken");
    Dish cofe=Dish("Coffee");
    Dish ff=Dish("French Fries");
    Dish onion=Dish("Onion Rings");
    Dish pizza=Dish("Pizza");
    int tableId;
    int num_of_orders=0;
};

#endif // DIALOG_H
