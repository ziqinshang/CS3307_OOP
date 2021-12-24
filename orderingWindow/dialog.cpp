/**
 * @brief This is Menu class, use it to show Menu window and set up buttons
 * @author Sha Liu, Chen Qu, Ziqin Shang
 */
#include "dialog.h"
#include "ui_dialog.h"
#include "menu.h"
#include "dish.h"
#include "order.h"
#include "orderqueue.h"
#include "mainwindow.h"

/**
 * @brief Constructor of Dialog, initialize dish[]
 * @param q
 * @param dish
 * @param parent
 */
Dialog::Dialog(std::shared_ptr<OrderQueue> q, Dish* dish[],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    q_ptr = q;

    for(int i=0; i<6;i++){
        //Chicken tacos
        if (dish[i]->getID()==0){
            chic_taco.setname(dish[i]->getname());
            chic_taco.setID(0);
            chic_taco.setprice(dish[i]->getprice());
            chic_taco.setrate(dish[i]->getrate());
            chic_taco.setTotalR(dish[i]->getTotalR());
            chic_taco.setTotalS(dish[i]->getTotalS());
            QString str0 = QString::number(dish[i]->getrate());
            ui->label_32->setText(str0);
        }

        //Chicken
        if (dish[i]->getID()==1){
            chicken.setname(dish[i]->getname());
            chicken.setID(1);
            chicken.setprice(dish[i]->getprice());
            chicken.setrate(dish[i]->getrate());
            chicken.setTotalR(dish[i]->getTotalR());
            chicken.setTotalS(dish[i]->getTotalS());
            QString str1 = QString::number(dish[i]->getrate());
            ui->label_33->setText(str1);
        }

        // Coffee
        if (dish[i]->getID()==2){

            cofe.setname(dish[i]->getname());
            cofe.setID(2);
            cofe.setprice(dish[i]->getprice());
            cofe.setrate(dish[i]->getrate());
            cofe.setTotalR(dish[i]->getTotalR());
            cofe.setTotalS(dish[i]->getTotalS());
            QString str2 = QString::number(dish[i]->getrate());
            ui->label_34->setText(str2);
        }

        //French Fries
        if (dish[i]->getID()==3){

            ff.setname(dish[i]->getname());
            ff.setID(3);
            ff.setprice(dish[i]->getprice());
            ff.setrate(dish[i]->getrate());
            ff.setTotalR(dish[i]->getTotalR());
            ff.setTotalS(dish[i]->getTotalS());
            QString str3 = QString::number(dish[i]->getrate());
            ui->label_35->setText(str3);

        }

        //Pizza
        if (dish[i]->getID()==4){
            pizza.setname(dish[i]->getname());
            pizza.setID(4);
            pizza.setprice(dish[i]->getprice());
            pizza.setrate(dish[i]->getrate());
            pizza.setTotalR(dish[i]->getTotalR());
            pizza.setTotalS(dish[i]->getTotalS());


            QString str4 = QString::number(dish[i]->getrate());
            ui->label_36->setText(str4);

        }

         // Onion rings
        if (dish[i]->getID()==5){

            onion.setname(dish[i]->getname());
            onion.setID(5);
            onion.setprice(dish[i]->getprice());
            onion.setrate(dish[i]->getrate());
            onion.setTotalR(dish[i]->getTotalR());
            onion.setTotalS(dish[i]->getTotalS());
            QString str5 = QString::number(dish[i]->getrate());
            ui->label_37->setText(str5);

        }

    }
}

    /**
     * @brief Destructor of Dialog
     */
    Dialog::~Dialog()
    {
        delete ui;
    }

    /**
     * @brief set table id 1
     */
    void Dialog::receiveData(){
        ui->label_40->setText("1");
        tableId = 1;
    }

    /**
     * @brief set table id 2
     */
    void Dialog::receiveData2(){
        ui->label_40->setText("2");
        tableId = 2;
    }

    /**
     * @brief set table id 3
     */
    void Dialog::receiveData3(){
        ui->label_40->setText("3");
        tableId = 3;
    }

    /**
     * @brief set table id 4
     */
    void Dialog::receiveData4(){
        ui->label_40->setText("4");
        tableId = 4;
    }

    /**
     * @brief set table id 5
     */
    void Dialog::receiveData5(){
        ui->label_40->setText("5");
        tableId = 5;
    }

    /**
     * @brief set table id 6
     */
    void Dialog::receiveData6(){
        ui->label_40->setText("6");
        tableId = 6;
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_clicked()
    {
        QString output;
        output.sprintf("%s %7d %13.2f","Chicken Tacos",1,5.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_4_clicked()
    {
        QString output;
        output.sprintf("%s %13d %13.2f","Chicken",1,6.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_6_clicked()
    {
        QString output;
        output.sprintf("%s %14d %13.2f","Coffee",1,2.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_8_clicked()
    {
        QString output;
        output.sprintf("%s %8d %13.2f","French Fries",1,3.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_10_clicked()
    {
        QString output;
        output.sprintf("%s %15d %13.2f","Pizza",1,10.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief add a dish
     */
    void Dialog::on_pushButton_12_clicked()
    {
        QString output;
        output.sprintf("%s %9d %13.2f","Onion Rings",1,5.99);
        ui->textEdit->append(output);
    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_3_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("Chicken Tacos"))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));

    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_5_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("Chicken   "))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));

    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_7_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("Coffee"))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));
    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_9_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("French Fries"))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));
    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_11_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("Pizza"))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));
    }

    /**
     * @brief remove a dish
     */
    void Dialog::on_pushButton_13_clicked()
    {
        QStringList lines = ui->textEdit->toPlainText().split("\n");
        int i = 0;
        while(i < lines.size())
        {
            QString line = lines.at(i);
            if(line.contains("Onion"))
            {
                lines.removeAt(i);
                break;
            }
            else
            {
                i++;
            }
        }
        ui->textEdit->setPlainText(lines.join("\n"));
    }

    //submit button
    /**
     * @brief if empty order, display "No items", else display all orders in text edit
     */
    void Dialog::on_pushButton_2_clicked()
    {

        if(ui->textEdit->document()->isEmpty())
        {
            QString str="No items.";
            ui->label_38->setText(str);
        }
        else
        {
            // Create a order

            Order order=Order(++num_of_orders,0,tableId);
            QStringList lines = ui->textEdit->toPlainText().split("\n");
            //int i = 0;
            //while(i < lines.size())
            for(int i=0; i<lines.size();i++)
                        {
                            QString line = lines.at(i);
                            if(line.contains("Chicken   "))
                            {
                                order.pushItems(chicken);
                                order.setprice(order.getprice()+6.99);
                                //i++;
                            }
                            if(line.contains("Chicken Tacos"))
                            {
                                order.pushItems(chic_taco);
                                order.setprice(order.getprice()+5.99);
                            }
                            if(line.contains("Coffee"))
                            {
                                order.pushItems(cofe);
                                order.setprice(order.getprice()+2.99);
                                //i++;
                            }
                            if(line.contains("French Fries"))
                            {
                                order.pushItems(ff);
                                order.setprice(order.getprice()+3.99);
                                //i++;
                            }
                            if(line.contains("Onion"))
                            {
                                order.pushItems(onion);
                                order.setprice(order.getprice()+5.99);
                                //i++;
                            }
                            if(line.contains("Pizza"))
                            {
                                order.pushItems(pizza);
                                order.setprice(order.getprice()+10.99);
                                //i++;
                            }
                        }
            //q.appendorder(order);
            q_ptr.get()->appendorder(order);
            QString str="Successful!";

            ui->label_38->setText(str);
            emit display();
            emit sendMoney(order.getprice());
            //ui->textEdit->clear();

        }

    }



