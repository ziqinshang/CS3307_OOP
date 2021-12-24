//
//  mainwindow.hpp
//  Qtexample
//
//  Created by David Shang on 2021-09-26.
//

#ifndef mainwindow_hpp
#define mainwindow_hpp

#include <stdio.h>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QLabel>
#include <QtQuickControls2/QtQuickControls2>
namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
    //function for update the text editor and other components when a the botton is pressed
    void handleButton();
    //function for update the text editor when a new item in the list is selected
    void listselect();
private:
    std::vector<QString> strvec;
    QPushButton *m_button;
    QLineEdit *m_line;
    QPlainTextEdit *m_block;
    QListWidget *m_list;
    QLabel *m_label;
    //QListWidgetItem *listitem;
};

#endif /* mainwindow_hpp */
