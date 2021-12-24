/**
 * @brief This is the order source file, which contains the methods
 * @author Sha Liu
 */
#include "order.h"
using namespace std;
using std::setw;


/**
 * @brief A constructor to initialize the attributes of objects of the class when created
 *        Return a Order type
 * @param oid
 * @param state
 * @param tid
 */
Order::Order(int oid,int state,int tid){
    orderID=oid;
    orderState=state;
    tableID=tid;
    dishNum=0; // how many dish in this order
    totalPrice=0;
}


/**
 * @brief A destructor to tear things down when objects are destroyed
 */
Order::~Order(void){

}

/**
 * @brief A getter, use it to get order ID
 * @return  order ID
 */
int Order::getorderID(){
    return orderID;
}


/**
 * @brief A getter, use it to get order's state
 * @return  order's  state
 */
int Order::getState(){
    return orderState;
}


/**
 * @brief A getter, use it to get table ID
 * @return order's  table ID
 */
int Order::gettableID(){
    return tableID;
}


/**
 * @brief print all items' names in order
 */
void Order::getItems(){
    for ( int i = 0; i < dishNum; i++ ){
        cout << setw( 7 )<< i << setw( 13 ) << orderedItems[ i ]->getname() << endl;
    }
}

/**
 * @brief Order::getitems_str
 * @return items
 */
std::string Order::getitems_str(){
    std::string items;
    for ( int i = 0; i < dishNum; i++ ){
        items += std::to_string(i) + " : " + orderedItems[ i ]->getname() + "  ";
    }
    return items;
}


/**
 * @brief A getter, use it to get the number of ordered dishes
 * @return order's the number of ordered dishes
 */
int Order::getdishNum(){
    return dishNum;
}

/**
 * @brief A setter, use it to set order ID
 * @param i
 */
void Order::setorderID(int i){
    orderID=i;
}

/**
 * @brief A setter, use it to set order's state
 * @param i
 */
void Order::setState(int i){
    orderState=i;
}

/**
 * @brief A setter, use it to set table ID
 * @param i
 */
void Order::settableID(int i){
    tableID=i;
}


/**
 * @brief push dish to ordereditems
 * @param dish
 */
void Order::pushItems(Dish dish){
    orderedItems[dishNum]= &dish;
    dishNum+=1;
}

/**
 * @brief compare orderId
 * @param order1
 * @return true if equal, otherwise false
 */
bool Order::ordercompare(Order order1){
    if(orderID == order1.getorderID()){
        return true;
    }
    else return false;
}

/**
 * @brief A setter, use it to set price
 * @param p
 */
void Order::setprice(double p){
    totalPrice=p;
}

/**
 * @brief A getter, use it to get the price of ordered dishes
 * @return totalPrice
 */
double Order::getprice(){
    return totalPrice;
}
