/**
 * @brief This is table class
 * @authors Ziqin Shang
 */

#include "Table.h"
using namespace std;
/**
 * @brief Constructor for table class
 * @param id
 * @param state
 * @param price
 */
Table::Table(int id,int state,double price){
    tableID = id;
    tablestate = state;
    tableprice = price;
}
/**
 * @brief Destructor for table class
 */
Table::~Table(void){
    
}

/**
 * @brief initialize and return a empty order, this order is under this specific table
 * @param ordernum
 * @return tmporder
 */
Order Table::neworder(int ordernum){
    Order tmporder(ordernum,1,tableID);
    return tmporder;
}

/**
 * @brief adding tips into total table price
 * @param tip
 */
void Table::tips(double tip){
    tableprice += tip;
}

/**
 * @brief return table price
 * @return tableprice
 */
double Table::checkout(){
    return tableprice;
}


/**
 * @brief set table price
 * @param p
 */
void Table::setPrice(double p){
    tableprice = p;
}


