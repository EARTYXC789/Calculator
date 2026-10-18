#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QWidget>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator() override;

private:
    QPushButton* numBtnList[10];
};
#endif // CALCULATOR_H
