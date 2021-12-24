#ifndef NEEDHELP_H
#define NEEDHELP_H

#include <QDialog>

namespace Ui {
class needHelp;
}

class needHelp : public QDialog
{
    Q_OBJECT

public:
    explicit needHelp(QWidget *parent = nullptr);
    ~needHelp();

private:
    Ui::needHelp *ui;
};

#endif // NEEDHELP_H
