/**
 * @brief This is the orderqueue header file.
 * @author Ziqin Shang
 */

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <queue>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "order.h"


class OrderQueue
{
private:
    std::queue<Order> orderqueue; //the dish queue waiting to be cooked

public:
    int getsize();
    std::string displayorders_str();
    void displayorders();
    void appendorder(Order);
    void poporder();
    void hurry(Order);
    Order findorderbytableid(int);
    Order getHead();
};

#endif //ORDERQUEUE_H
