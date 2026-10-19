#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <QPushButton>
#include <QChar>
#include <QWidget>
#include <QLineEdit>

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

    QLineEdit* display;
    QLineEdit* funDisplay;

    double firstNum = 0;
    double secondNum = 0;
    QChar operation;

    bool newInput = true;


private slots:
    void Calculate();
    void FunCalculate(const QChar &operation);
};
#endif // CALCULATOR_H
