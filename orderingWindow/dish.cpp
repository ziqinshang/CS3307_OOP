/**
 * @brief This is Dish class
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */

#include "dish.h"
using namespace std;

/**
 * @brief A constructor to initialize the attributes of objects of the class when created
 *        Return a Dish type
 * @param input
 */
Dish::Dish(std::string input){
    name=input;
    pic="";
    price=0; // Dish's price
    dishID=0; //Dish's ID
    totalRate=0; // Total of all ratings
    totalServed=0; // The total number of times the dish was rate
    rate=0;
}

/**
 * @brief A destructor to tear things down when objects are destroyed
 */
Dish::~Dish(void){

}

/**
 * @brief A getter, use it to get name of dish
 * @return dish's name
 */
std::string Dish::getname(){
    return name;
}


/**
 * @brief A getter, use it to get name of dish's picture
 * @return name of dish's picture
 */
std::string Dish::getpic(){
    return pic;
}

/**
 * @brief A getter, use it to get name of dish's picture
 * @return name of dish's picture
 */
double Dish::getprice(){
    return price;
}

/**
 * @brief A getter, use it to get dish's ID
 * @return dish's ID
 */
int Dish::getID(){
    return dishID;
}

/**
 * @brief A getter, use it to get dish's total rating
 * @return dish's total rating
 */
int Dish::getTotalR(){
    return totalRate;
}

/**
 * @brief A getter, use it to get the dish's rating times
 * @return dish's rating times
 */
int Dish::getTotalS(){
    return totalServed;
}

/**
 * @brief A getter, use it to get the dish's rate
 * @return dish's rate
 */
int Dish::getrate(){
    return rate;
}

/**
 * @brief A setter, use it to set dish's name
 * @param i
 */
void Dish::setname(std::string i){
    name=i;
}

/**
 * @brief A setter, use it to set name of dish's picture
 * @param i
 */
void Dish::setpic(std::string i){
    pic=i;
}

/**
 * @brief A setter, use it to set dish's price
 * @param i
 */
void Dish::setprice(double i){
    price=i;
}

/**
 * @brief A setter, use it to set dish's ID
 * @param i
 */
void Dish::setID(int i){
    dishID=i;
}

/**
 * @brief A setter, use it to set dish's total rate
 * @param i
 */
void Dish::setTotalR(int i){
    totalRate=i;
}

/**
 * @brief A setter, use it to set total rating times of the dish
 * @param i
 */
void Dish::setTotalS(int i){
    totalServed=i;
}

/**
 * @brief A setter, use it to set dish's average rate
 * @param i
 */
void Dish::setrate(int i){
    rate=i;
}

/**
 * @brief A setter, use it to set dish's average rate
 * @param i
 */
void Dish::updaterate(int i){
    totalServed++;
    totalRate = totalRate + i;
}

/**
 * @brief A method to calculate average rate of the dish
 * @return the average rate of this dish, and it can return -1 in some case
 */
int Dish::averageRate(){
    if (totalRate==0||totalServed==0){
        cout<<"No one scored this dish"<<endl;
        return -1;
    }
    else {
        rate=totalRate/totalServed;
        return rate;
    }
}
