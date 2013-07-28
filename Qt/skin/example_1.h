#ifndef EXAMPLE_1_H
#define EXAMPLE_1_H

#include <QWidget>

namespace Ui {
class example_1;
}

class Example_1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Example_1(QWidget *parent = 0);
    ~Example_1();
    
private:
    Ui::example_1 *ui;
};

#endif // EXAMPLE_1_H
