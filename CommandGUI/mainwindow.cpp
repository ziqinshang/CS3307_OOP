//  mainwindow.cpp
//  Qtexample
//
//  Created by David Shang on 2021-09-26.
//

#include "mainwindow.hpp"
#include "command.hpp"
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    // Create the interface components, make "this" the parent
    m_button = new QPushButton("EXECUTE", this);
    m_line = new QLineEdit(this);
    m_block = new QPlainTextEdit(this);
    m_list = new QListWidget(this);
    m_label = new QLabel(this);
    //listitem = new QListWidgetItem(m_list);
    // set size and location of the button
    m_button->setGeometry(210,450,200,100);
    m_line->setGeometry(10,10, 400, 30);
    m_block->setGeometry(10, 50, 400, 400);
    m_block->setReadOnly(1);
    m_list->setGeometry(10, 450, 200, 200);
    m_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_label->setGeometry(300, 600, 50, 50);
    // Connect button signal to appropriate slot
    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
    connect(m_list, &QListWidget::itemSelectionChanged, this, &MainWindow::listselect);
    //connect(m_list, &QListWidget::itemPressed(QListWidgetItem *), this, &MainWindow::listselect(QListWidgetItem *));
}
void MainWindow::listselect()
{
    //set the row number as the row currently selected
    int rownum = m_list->currentRow();
    //retrieve the output from a string vector and pop it back to text editor
    m_block->setPlainText(strvec.at(rownum));
}
void MainWindow::handleButton()
{
    //get the command from line input
    QString cmd = m_line->text();
    //call the class constructor while convert qstring to string
    command k(cmd.toStdString());
    //execute the command within object
    k.execute();
    //get the execution result from the executed object
    std::string tmps = k.get_result();
    //get the return code from the executed objected
    int tmpcode = k.get_code();
    //convert return code int to qstring
    QString code = QString::number(tmpcode);
    //convert execution result string to qstring
    QString results = QString::fromStdString(tmps);
    //add the execution result into string vector as a history
    strvec.push_back(results);
    //concatenate command and return code
    QString listitem = cmd + "(" + code +")";
    //pop the return code into label
    m_label->setText(code);
    //pop the concatednated command and return code into list
    m_list->addItem(listitem);
    //pop the execution result into text editor
    m_block->setPlainText(results);
}
