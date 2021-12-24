/**
 * @brief This is Restaurant class, use it to show Restaurant window and set up buttons
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#include "restaurant.h"
#include "ui_restaurant.h"
#include "mainwindow.h"
#include "dialog.h"
#include "checkoutwindow.h"

/**
 * @brief Constructor of Restaurant
 *        Connect 3 windows by buttons
 * @param q
 * @param parent
 */
Restaurant::Restaurant(std::shared_ptr<OrderQueue> q, QWidget *parent) :
    QDialog(parent),
    t1(1,0,0),t2(2,0,0),t3(3,0,0),t4(4,0,0),t5(5,0,0),t6(6,0,0),
    ui(new Ui::Restaurant)
{
    ui->setupUi(this);
    q_ptr = q;

    // Chicken Taco
        Dish chic_taco=Dish("Chicken Tacos");
        chic_taco.setprice(5.99);
        chic_taco.setID(0);

        // Chicken
        Dish chicken=Dish("Chicken");
        chicken.setprice(6.99);
        chicken.setID(1);

        // Coffee
        Dish cofe=Dish("Coffee");
        cofe.setprice(2.99);
        cofe.setID(2);

        // French fries
        Dish ff=Dish("French Fries");
        ff.setprice(3.99);
        ff.setID(3);

        // Pizza
        Dish pizza=Dish("Pizza");
        pizza.setprice(10.99);
        pizza.setID(4);

        // Onion rings
        Dish onion=Dish("Onion Rings");
        onion.setprice(5.99);
        onion.setID(5);

        Dish *d[6];
        d[0]= &chicken;
        d[1]= &chic_taco;
        d[2]=&cofe;
        d[3]=&ff;
        d[4]=&pizza;
        d[5]=&onion;
    Dialog *menu = new Dialog(q_ptr,d);
    MainWindow *m = new MainWindow(q_ptr);

    connect(m, SIGNAL(order1()), menu, SLOT(receiveData())); // click table 1 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp1()), this, SLOT(receiveData())); // click table 1 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry1()), this, SLOT(handle_hurry_button_1())); // click table 1 Hurry Button, then put the order of table 1 at the first position
    connect(m, SIGNAL(popupWindow1()), this, SLOT(popup1())); // click table 1 checkOut Button, then pop up checkOut window

    connect(m, SIGNAL(order2()), menu, SLOT(receiveData2())); // click table 2 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp2()), this, SLOT(receiveData2())); // click table 2 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry2()), this, SLOT(handle_hurry_button_2())); // click table 2 Hurry Button, then put the order of table 2 at the first position
    connect(m, SIGNAL(popupWindow2()), this, SLOT(popup2())); // click table 2 checkOut Button, then pop up checkOut window

    connect(m, SIGNAL(order3()), menu, SLOT(receiveData3())); // click table 3 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp3()), this, SLOT(receiveData3())); // click table 3 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry3()), this, SLOT(handle_hurry_button_3())); // click table 3 Hurry Button, then put the order of table 3 at the first position
    connect(m, SIGNAL(popupWindow3()), this, SLOT(popup3())); // click table 3 checkOut Button, then pop up checkOut window

    connect(m, SIGNAL(order4()), menu, SLOT(receiveData4())); // click table 4 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp4()), this, SLOT(receiveData4())); // click table 4 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry4()), this, SLOT(handle_hurry_button_4())); // click table 4 Hurry Button, then put the order of table 4 at the first position
    connect(m, SIGNAL(popupWindow4()), this, SLOT(popup4())); // click table 4 checkOut Button, then pop up checkOut window

    connect(m, SIGNAL(order5()), menu, SLOT(receiveData5())); // click table 5 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp5()), this, SLOT(receiveData5())); // click table 5 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry5()), this, SLOT(handle_hurry_button_5())); // click table 5 Hurry Button, then put the order of table 5 at the first position
    connect(m, SIGNAL(popupWindow5()), this, SLOT(popup5())); // click table 5 checkOut Button, then pop up checkOut window

    connect(m, SIGNAL(order6()), menu, SLOT(receiveData6())); // click table 6 order Button, then display table id on menu UI
    connect(m, SIGNAL(NeedHelp6()), this, SLOT(receiveData6())); // click table 6 NeedHelp Button, then display table id on restaurant UI
    connect(m, SIGNAL(hurry6()), this, SLOT(handle_hurry_button_6())); // click table 6 Hurry Button, then put the order of table 6 at the first position
    connect(m, SIGNAL(popupWindow6()), this, SLOT(popup6())); // click table 1 checkOut Button, then pop up checkOut window

    connect(menu,SIGNAL(display()), this, SLOT(handle_finish_button_display_ptr())); // click submit button on menu, then display order on menu UI

    connect(this, SIGNAL(refresh()), this, SLOT(Hurry_display()));
    connect(this, SIGNAL(finishOrder()), this, SLOT(removeOrder()));

    m->show();
    menu->show();

}

/**
 * @brief Destructor of Restaurant
 */
Restaurant::~Restaurant()
{
    delete ui;
}

/**
 * @brief pop up a checkOut window after click table 1 check out Button
 */
void Restaurant::popup1(){
    checkoutWindow chec(t1.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief pop up a checkOut window after click table 2 check out Button
 */
void Restaurant::popup2(){
    checkoutWindow chec(t2.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief pop up a checkOut window after click table 3 check out Button
 */
void Restaurant::popup3(){
    checkoutWindow chec(t3.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief pop up a checkOut window after click table 4 check out Button
 */
void Restaurant::popup4(){
    checkoutWindow chec(t4.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief pop up a checkOut window after click table 5 check out Button
 */
void Restaurant::popup5(){
    checkoutWindow chec(t5.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief pop up a checkOut window after click table 6 check out Button
 */
void Restaurant::popup6(){
    checkoutWindow chec(t6.checkout());
    chec.setModal(true);
    chec.exec();
}

/**
 * @brief set table id 1 if it needs help
 */
void Restaurant::receiveData(){
    ui->lineEdit->setText("1");
}

/**
 * @brief set table id 2 if it needs help
 */
void Restaurant::receiveData2(){
    ui->lineEdit->setText("2");
}

/**
 * @brief set table id 3 if it needs help
 */
void Restaurant::receiveData3(){
    ui->lineEdit->setText("3");
}

/**
 * @brief set table id 4 if it needs help
 */
void Restaurant::receiveData4(){
    ui->lineEdit->setText("4");
}

/**
 * @brief set table id 5 if it needs help
 */
void Restaurant::receiveData5(){
    ui->lineEdit->setText("5");
}

/**
 * @brief set table id 6 if it needs help
 */
void Restaurant::receiveData6(){
    ui->lineEdit->setText("6");
}

/**
 * @brief find table id 1 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_1()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(1));
}

/**
 * @brief find table id 2 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_2()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(2));
}

/**
 * @brief find table id 3 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_3()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(3));
}

/**
 * @brief find table id 4 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_4()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(4));
}

/**
 * @brief find table id 5 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_5()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(5));
}

/**
 * @brief find table id 6 and put it in the front of orer queue
 */
void Restaurant::handle_hurry_button_6()
{
    q_ptr.get()->hurry(q_ptr.get()->findorderbytableid(6));
}


/**
 * @brief display order queue in text browser
 */
void Restaurant::handle_finish_button_display_ptr()
{

    std::string tmporder = q_ptr.get()->displayorders_str();
    QString orderq = QString::fromStdString(tmporder);
    ui->textBrowser->setText(orderq);
}

/**
 * @brief display order queue in text browser
 */
void Restaurant::Hurry_display()
{
    std::string tmporder = q_ptr.get()->displayorders_str();
    QString orderq = QString::fromStdString(tmporder);
    ui->textBrowser->setText(orderq);
    //ui->textBrowser->setText("999");
}

/**
 * @brief send a signal after click refresh Button
 */
void Restaurant::on_pushButton_2_clicked()
{
    emit refresh();
}

/**
 * @brief send a signal after click Finish Order Button
 */
void Restaurant::on_pushButton_clicked()
{
    emit finishOrder();

}

/**
 * @brief remove order
 */
void Restaurant::removeOrder(){
    int tmpTableId = q_ptr.get()->getHead().gettableID();
    double tmpTablePrice = q_ptr.get()->getHead().getprice();

    if(tmpTableId == 1){
        t1.setPrice(tmpTablePrice);
    }else if(tmpTableId == 2){
        t2.setPrice(tmpTablePrice);
    }else if(tmpTableId == 3){
        t3.setPrice(tmpTablePrice);
    }else if(tmpTableId == 4){
        t4.setPrice(tmpTablePrice);
    }else if(tmpTableId == 5){
        t5.setPrice(tmpTablePrice);
    }else if(tmpTableId == 6){
        t6.setPrice(tmpTablePrice);
    }

    q_ptr.get()->poporder();
}
