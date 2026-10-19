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
    QPushButton* addBtn;
    QPushButton* subBtn;
    QPushButton* tBtn;
    QPushButton* dBtn;
    QPushButton* eBtn;
};
#endif // CALCULATOR_H
