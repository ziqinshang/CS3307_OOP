/**
 * @brief This is main class, use it to show window
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#include "mainwindow.h"
#include "restaurant.h"
#include <QApplication>
#include "menu.h"
#include "dish.h"
#include "dialog.h"
#include "checkout.h"

/**
 * @brief use it to show window
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<OrderQueue> q_ptr(std::make_shared<OrderQueue>());

    Restaurant res(q_ptr);
    res.show();

    return a.exec();
}
