/**
 * @brief This is the description for table.cpp file
 * @authors Ziqin Shang
 */

#ifndef Table_h
#define Table_h

#include <stdio.h>
#include "dish.h"
#include "order.h"

class Table{
private:
    int tableID;
    int tablestate;
    double tableprice;
public:
    Table(int,int,double);
    ~Table();
    Order neworder(int);
    void hurry(int);
    void tips(double);
    double checkout();
    void setPrice(double);
};
#endif /* Table_h */
