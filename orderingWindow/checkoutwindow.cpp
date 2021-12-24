/**
 * @brief This is checkout class, use it to show checkout window and set up buttons
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#include "checkoutwindow.h"
#include "ui_checkoutwindow.h"

/**
 * @brief Constructor of checkoutWindow class
 * @param p
 * @param parent
 */
checkoutWindow::checkoutWindow(double p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkoutWindow)
{
    ui->setupUi(this);
    price = p;
    QString str = QString::number(price,'f',2);
    ui->label_4->setText(str);
}

/**
 * @brief Destructor of checkoutWindow class
 */
checkoutWindow::~checkoutWindow()
{
    delete ui;
}

/**
 * @brief calculate total price after add 10% tip
 */
void checkoutWindow::on_pushButton_clicked()
{
    price=1.1*price;
    QString str = QString::number(price);
    ui->label_14->setText(str);
    price=price-0.1*price;
}
// 12% tip Button
/**
 * @brief calculate total price after add 12% tip
 */
void checkoutWindow::on_pushButton_2_clicked()
{
    price=1.12*price;
    QString str = QString::number(price,'f',2);
    ui->label_14->setText(str);
    price=price-0.12*price;

}
// 15% tip Button
/**
 * @brief calculate total price after add 15% tip
 */
void checkoutWindow::on_pushButton_3_clicked()
{
    price=1.15*price;
    QString str = QString::number(price,'f',2);
    ui->label_14->setText(str);
    price=price-0.15*price;
}

// input amount of tip and confirm Button
/**
 * @brief input amount of tip and confirm Button, then calculate total price
 */
void checkoutWindow::on_pushButton_4_clicked()
{
    QString tip= ui->lineEdit->text();
    int tipInt=tip.toInt();
    price+=tipInt;
    QString str = QString::number(price,'f',2);
    ui->label_14->setText(str);
    price-=tipInt;
}


