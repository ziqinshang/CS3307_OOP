/**
 * @brief This is the orderqueue source file, which contains the methods
 * @author Ziqin Shang
 */
#include <queue>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "orderqueue.h"
#include "kitchen.hpp"
#include "order.h"
#include "Table.h"
using namespace std;

/**
 * @brief get size of order queue
 * @return size of order queue
 */
int OrderQueue::getsize(){
    return orderqueue.size();
}

/**
 * @brief display all orders in string type
 * @return orders_str
 */
std::string OrderQueue::displayorders_str(){
    std::string orders_str;
    int queueSize = orderqueue.size();
    for(int i=0; i<queueSize; i++){
        std::string current_str;
        current_str = "TableID: " + std::to_string(orderqueue.front().gettableID());
        current_str += " OrderID: " + std::to_string(orderqueue.front().getorderID());
        current_str += "\n";
        current_str += "Items: " + orderqueue.front().getitems_str();
        current_str += "\n";
        orders_str.append(current_str);
        orderqueue.push(orderqueue.front());
        orderqueue.pop();
    }
    return orders_str;
}

/**
 * @brief display all orders
 */
void OrderQueue::displayorders(){
    int queueSize = orderqueue.size();
    for(int i=0; i<queueSize; i++){
        cout << orderqueue.front().getorderID()<< "->";
        orderqueue.push(orderqueue.front());
        orderqueue.pop();
    }
    cout<<endl;
}

/**
 * @brief add new order into orderqueue
 * @param neworder
 */
void OrderQueue::appendorder(Order neworder){
    orderqueue.push(neworder);
}

/**
 * @brief pop orders
 */
void OrderQueue::poporder(){
    orderqueue.pop();
}

/**
 * @brief put the oder in the front of orderqueue
 * @param priorityorder
 */
void OrderQueue::hurry(Order priorityorder){
    int queueSize = orderqueue.size();
    std::queue<Order> neworderqueue;
    neworderqueue.push(priorityorder);
    for(int i=0; i<queueSize; i++){
        if (priorityorder.ordercompare(orderqueue.front())) {
            orderqueue.pop();
            continue;
        }
        neworderqueue.push(orderqueue.front());
        orderqueue.pop();
    }
    orderqueue = neworderqueue;
}

/**
 * @brief find the order by table id
 * @param tableid
 * @return a empty order
 */
Order OrderQueue::findorderbytableid(int tableid){
    int queueSize = orderqueue.size();
    std::queue<Order> neworderqueue(orderqueue);
    for(int i=0; i<queueSize; i++){
        if (neworderqueue.front().gettableID()==tableid) {
            return neworderqueue.front();
        }
        neworderqueue.pop();
    }
    return Order(-1, -1, -1);
}

/**
 * @brief get the first element of order queue
 * @return the first element of order queue
 */
Order OrderQueue::getHead(){
    return orderqueue.front();
}
