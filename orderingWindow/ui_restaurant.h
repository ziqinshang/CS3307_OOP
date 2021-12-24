/********************************************************************************
** Form generated from reading UI file 'restaurant.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANT_H
#define UI_RESTAURANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Restaurant
{
public:
    QFrame *line;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton;
    QFrame *line_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Restaurant)
    {
        if (Restaurant->objectName().isEmpty())
            Restaurant->setObjectName(QString::fromUtf8("Restaurant"));
        Restaurant->resize(751, 603);
        line = new QFrame(Restaurant);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 260, 761, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(Restaurant);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 111, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        textBrowser = new QTextBrowser(Restaurant);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 50, 691, 201));
        label_2 = new QLabel(Restaurant);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 290, 101, 16));
        label_2->setFont(font);
        label_3 = new QLabel(Restaurant);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 330, 47, 13));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);
        label_5 = new QLabel(Restaurant);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 330, 131, 16));
        label_5->setFont(font1);
        pushButton = new QPushButton(Restaurant);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 460, 111, 31));
        pushButton->setFont(font);
        line_2 = new QFrame(Restaurant);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(7, 400, 741, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(Restaurant);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 329, 51, 21));
        lineEdit->setFont(font1);
        pushButton_2 = new QPushButton(Restaurant);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(524, 10, 161, 31));

        retranslateUi(Restaurant);

        QMetaObject::connectSlotsByName(Restaurant);
    } // setupUi

    void retranslateUi(QDialog *Restaurant)
    {
        Restaurant->setWindowTitle(QCoreApplication::translate("Restaurant", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Restaurant", "Order Queue:", nullptr));
        label_2->setText(QCoreApplication::translate("Restaurant", "Need Help", nullptr));
        label_3->setText(QCoreApplication::translate("Restaurant", "Table", nullptr));
        label_5->setText(QCoreApplication::translate("Restaurant", "needs assistance", nullptr));
        pushButton->setText(QCoreApplication::translate("Restaurant", "Finish Order", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Restaurant", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Restaurant: public Ui_Restaurant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANT_H
