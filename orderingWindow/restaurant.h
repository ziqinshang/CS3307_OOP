/**
 * @brief This is the restaurant header file.
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QDialog>
#include <QtWidgets/QLabel>
#include "orderqueue.h"
#include "Table.h"

namespace Ui {
class Restaurant;
}

class Restaurant : public QDialog
{
    Q_OBJECT
signals:
    void refresh();
    void finishOrder();
public:
    explicit Restaurant(std::shared_ptr<OrderQueue> q, QWidget *parent = nullptr);

    ~Restaurant();

private slots:
    void receiveData();
    void receiveData2();
    void receiveData3();
    void receiveData4();
    void receiveData5();
    void receiveData6();
    void handle_finish_button_display_ptr();
    void handle_hurry_button_1();
    void handle_hurry_button_2();
    void handle_hurry_button_3();
    void handle_hurry_button_4();
    void handle_hurry_button_5();
    void handle_hurry_button_6();
    void Hurry_display();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void removeOrder();
    void popup1();
    void popup2();
    void popup3();
    void popup4();
    void popup5();
    void popup6();

private:
    Ui::Restaurant *ui;
    QLabel *needhelp_display;
    std::shared_ptr<OrderQueue> q_ptr;
    Table t1;
    Table t2;
    Table t3;
    Table t4;
    Table t5;
    Table t6;
};

#endif // RESTAURANT_H
