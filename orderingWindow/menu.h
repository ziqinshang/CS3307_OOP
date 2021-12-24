#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "orderqueue.h"
#include "dish.h"
#include "order.h"

namespace Ui {
class Dialog;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    //OrderQueue q, Dish* d[]
    explicit Menu(OrderQueue q, Dish* d[],QWidget *parent = 0);
    ~Menu();

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

private:
    Ui::Dialog *ui;
    OrderQueue q;
    Dish chic_taco=Dish("Chicken Tacos");
    Dish chicken=Dish("Chicken");
    Dish cofe=Dish("Coffee");
    Dish ff=Dish("French Fries");
    Dish onion=Dish("Onion Rings");
    Dish pizza=Dish("Pizza");
};

#endif // MENU_H
