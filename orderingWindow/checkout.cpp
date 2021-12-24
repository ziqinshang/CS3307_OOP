
#include "checkout.h"
#include "restaurant.h"
#include "QGridLayout"
#include "QLineEdit"
#include "vector"
#include "string"
#include "QVector"

// 一些需要全局调用的参数
float totalPrice = 0.0;
float finalPrice = 0.0;
//make sample order according to api
QVector<Dish> orderdishes = {Dish("chicken tacos"), Dish("chiken"), Dish("coffee")};
Order* curOrder = new Order(1,1,1);
QVector<QLineEdit*> dishes_rating;
QLineEdit * tip_amount;
QLineEdit * finalPrice_real;

//总窗口
CheckOut::CheckOut(std::shared_ptr<OrderQueue> q, QWidget *parent)
  : QDialog(parent)
{
    Restaurant restaurant(q);
    q_ptr = q;
  // Create the button, make "this" the parent
  hurry_button = new QPushButton("HURRY", this);
  // set size and location of the button
  hurry_button->setGeometry(210,450,200,100);
    needhelp_button = new QPushButton("NEEDHELP", this);
    needhelp_button->setGeometry(600,450,200,100);
  // Connect button signal to appropriate slot
    connect(hurry_button, &QPushButton::released, this, &::CheckOut::handle_hurry_button_1);
//     connect(hurry_button, &QPushButton::released, this, &::MainWindow::handle_hurry_button_1);

    checkout_button = new QPushButton("CheckOut", this);
    checkout_button->setGeometry(1000,450,200,100);
    connect(checkout_button, &QPushButton::released, this, &::CheckOut::on_checkout_clicked);
}

void CheckOut::handle_hurry_button_1()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(1));
}

void CheckOut::handle_hurry_button_2()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(2));

}

//点击checkout之后的子窗口
void CheckOut::on_checkout_clicked()
{

    // make order list str
    std::string orderlist_str = "";
    for(int i=0; i<orderdishes.size(); i++){
        orderlist_str = orderlist_str + orderdishes[i].getname() + ":" + std::to_string(orderdishes[i].getprice()).substr(0,4);
        totalPrice += orderdishes[i].getprice();
        orderlist_str += '\n';
    }

    // define window
    QWidget *checkout_window = new QWidget();
    checkout_window->setWindowTitle("CheckOut Menu");
    checkout_window->resize(900, 300);

    // define controller
    // dishes模块ui
    QLabel *checkout_label = new QLabel(checkout_window);
    QLabel *table_id = new QLabel(checkout_window);
    QLabel *real_table_id = new QLabel(checkout_window);
    QLabel *order_dishes_label = new QLabel(checkout_window);
    QLabel *price_label = new QLabel(checkout_window);
    QLabel *price_real = new QLabel(checkout_window);
    QLineEdit *dish_box = new QLineEdit(checkout_window);

    // dishes模块中部件的设计
    checkout_label->setText("CheckOut");
    checkout_label->setGeometry(20,20,50,50);
    table_id->setText("TableID:");
    table_id->setGeometry(20,40,50,50);
    real_table_id->setText(QString::fromStdString(std::to_string(curOrder->gettableID())));
    real_table_id->setGeometry(80,40,50,50);
    order_dishes_label->setText("Order_dishes:");
    order_dishes_label->setGeometry(20,60,100,50);
    dish_box->setGeometry(20,100,200,100);
    dish_box->setReadOnly(true);
    price_label->setText("Prices:");
    price_label->setGeometry(20,200,50,50);
    price_real->setText(QString::fromStdString(std::to_string(totalPrice).substr(0,5)));
    price_real->setGeometry(80,200,50,50);

    // 显示已点菜品
    QString orderlist_qstr = QString::fromStdString(orderlist_str);
    dish_box->setText(orderlist_qstr);

    // Tip模块的ui
    QLabel *tip_label = new QLabel(checkout_window);
    QLabel *mention_label1 = new QLabel(checkout_window);
    QLabel *mention_label2 = new QLabel(checkout_window);

    // 百分比小费按钮
    QPushButton *tip_button1 = new QPushButton(checkout_window);
    QPushButton *tip_button2 = new QPushButton(checkout_window);
    QPushButton *tip_button3 = new QPushButton(checkout_window);

    // 具体数值小费按钮
    tip_amount = new QLineEdit(checkout_window);

    // tip模块的ui设计
    tip_label->setText("Tips");
    tip_label->setGeometry(300,20,50,50);
    mention_label1->setText("By Percent:");
    mention_label1->setGeometry(300,40,100,50);
    mention_label2->setText("By Amount:");
    mention_label2->setGeometry(300,120,100,50);
    tip_amount->setGeometry(360,135,50,20);
    tip_button1->setText("10%");
    tip_button1->setGeometry(300,80,50,50);
    tip_button2->setText("12%");
    tip_button2->setGeometry(350,80,50,50);
    tip_button3->setText("15%");
    tip_button3->setGeometry(400,80,50,50);
    tip_button1->setObjectName("tip_button1");
    tip_button2->setObjectName("tip_button2");
    tip_button3->setObjectName("tip_button3");

    // 三种不同小费比例的槽函数
    connect(tip_button1, &QPushButton::released, this, &::CheckOut::percent_clicked);
    connect(tip_button2, &QPushButton::released, this, &::CheckOut::percent_clicked);
    connect(tip_button3, &QPushButton::released, this, &::CheckOut::percent_clicked);

    // Rating模块ui
    QLabel *rating_label = new QLabel(checkout_window);
    rating_label->setText("Rating");
    rating_label->setGeometry(600,20,50,50);

    // 根据具体order显示
    for(int i=0; i<orderdishes.size(); i++){
        QLabel *dish = new QLabel(checkout_window);
        QLineEdit *dish_rating = new QLineEdit(checkout_window);
        dish->setText(QString::fromStdString(orderdishes[i].getname()));
        dish->setGeometry(600, 60+i*30, 100, 50);
        dish_rating->setGeometry(700, 75+i*30, 50, 20);
        dishes_rating.append(dish_rating);
    }

    // submit
    QPushButton *submit_button = new QPushButton(checkout_window);
    submit_button->setText("Submit");
    submit_button->setGeometry(600, 200, 50, 20);

    QLabel * finalPrice = new QLabel(checkout_window);
    finalPrice->setText("Final Price");
    finalPrice->setGeometry(600, 170, 70, 20);
    finalPrice_real = new QLineEdit(checkout_window);
    finalPrice_real->setGeometry(700, 170, 70, 20);

    //submit点击之后的槽函数
    connect(submit_button, &QPushButton::released, this, &::CheckOut::on_submit_clicked);

    // 显示窗口
    checkout_window->show();
}

// 根据不同的百分比小费更新最终价格
void CheckOut::percent_clicked(){
    QString buttonName = sender()->objectName();
    if(buttonName.compare("tip_button1") == 0){
        totalPrice += totalPrice*0.1;
        std::cout << totalPrice;
        return;
    }else if(buttonName.compare("tip_button2") == 0){
        totalPrice += totalPrice*0.12;
        std::cout << totalPrice;
        return;
    }else if(buttonName.compare("tip_button3") == 0){
        totalPrice += totalPrice*0.15;
        std::cout << totalPrice;
        return;
    }
}

// 点击submit之后的操作
void CheckOut::on_submit_clicked(){
    // 更具具体小费数值进行最终价格更新
    finalPrice = totalPrice + tip_amount->text().toFloat();
    finalPrice_real->setText(QString::fromStdString(std::to_string(finalPrice)));

    // 更新餐品rating
    for(int i=0; i<dishes_rating.size(); i++){
        int currate = std::atoi(dishes_rating[i]->text().toStdString().c_str());
        orderdishes[i].setrate(currate);
        std::cout << orderdishes[i].getname() << ":" << currate << std::endl;
    }
}
