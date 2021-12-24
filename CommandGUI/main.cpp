#include "mainwindow.hpp"
#include "command.hpp"
#include <QtWidgets/QApplication>
 
int main(int argc, char *argv[])
{
    //string tmp = "gcc --version";
//    string tmp = "ps";
//    command k(tmp);
//    string tmp2 = k.get_command();
//    k.execute();
  QApplication app(argc, argv);
  MainWindow mainWindow;
    mainWindow.showMaximized();
    mainWindow.resize(420,700);
  return app.exec();
}
 
