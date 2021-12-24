#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <stdio.h>
#include <QDialog>
#include <QtWidgets/QPushButton>
#include "orderqueue.h"
#include "order.h"
#include "QLabel"
#include "QLineEdit"
namespace Ui {
  class CheckOut;
}
class CheckOut : public QDialog
{
  Q_OBJECT
public:
  explicit CheckOut(std::shared_ptr<OrderQueue> q, QWidget *parent = nullptr);
private slots:
   void handle_hurry_button_1();
   void handle_hurry_button_2();
    void on_checkout_clicked();
    void on_submit_clicked();
    void percent_clicked();
private:
    std::shared_ptr<OrderQueue> q_ptr;
    QPushButton *hurry_button;
    QPushButton *needhelp_button;
    QPushButton *checkout_button;

};

#endif // CHECKOUT_H
