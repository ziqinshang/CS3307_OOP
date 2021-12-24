/**
 * @brief This is head file of checkoutwindow.cpp file.
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */

#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QDialog>

namespace Ui {
class checkoutWindow;
}

class checkoutWindow : public QDialog
{
    Q_OBJECT
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
public:
    explicit checkoutWindow(double price, QWidget *parent = nullptr);
    ~checkoutWindow();

private:
    Ui::checkoutWindow *ui;
    double price;
};

#endif // CHECKOUTWINDOW_H
