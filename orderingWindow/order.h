
/**
 * @brief This is the order header file.
 * @author Sha Liu
 */

#ifndef ORDER_H
#define ORDER_H

#include <exception>
#include <new>
#include <typeinfo>
#include <ios>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include "dish.h"

class Dish;
class Order{

private:
    int orderID;
    int orderState;
    int tableID;
    int dishNum; // how many dish in this order
    double totalPrice;
    Dish* orderedItems[100];//100 dishes at most

public:
    //A constructor
    Order(int,int,int);

    //A destructor
    ~Order();

    //Settet
    void setprice(double);

    //Getters
    int getorderID();
    int getState();
    int gettableID();
    int getdishNum();
    double getprice();
    void getItems();//print all items' names in order
    std::string getitems_str();


    //A setter
    void setorderID(int);
    void setState(int);
    void settableID(int);

    //push dish to ordereditems
    void pushItems(Dish);

    //a function that compare orders
    bool ordercompare(Order);

};

#endif // ORDER_H
