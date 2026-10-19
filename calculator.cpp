#include "calculator.h"

#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Calculator");
    resize(400,600);
    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignTop);

    funDisplay = new QLineEdit(this);
    funDisplay->setReadOnly(true);
    funDisplay->setAlignment(Qt::AlignRight);
    funDisplay->setMinimumHeight(30);
    layout->addWidget(funDisplay, 0, 0, 1, 6);

    display = new QLineEdit(this);
    display->setText("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(60);
    layout->addWidget(display, 1, 0, 1, 6);


    for (int i = 9 , index = 0; i >= 0; i--, index++) {
        numBtnList[index] = new QPushButton(QString::number(i),this);

        numBtnList[index]->setMinimumHeight(60);

        int row, col;
        if (i == 0) {
            row = 6;
            col = 1;
        }
        else {
            row = (9 - i) / 3 + 3;
            col = (i - 1) % 3;
        }

        layout->addWidget(numBtnList[index], row, col);

        connect(numBtnList[index], &QPushButton::clicked,this, [this, i]() {

            if (newInput || display->text() == "0") {
                display->setText(QString::number(i));
                newInput = false;
            }
            else {
                display->setText(display->text() + QString::number(i));
            }
        });

    }

    addBtn = new QPushButton("+");
    subBtn = new QPushButton("-");
    tBtn = new QPushButton("x");
    dBtn = new QPushButton("/");
    eBtn = new QPushButton("=");
    layout->addWidget(addBtn, 2 , 3);
    layout->addWidget(subBtn, 3 , 3);
    layout->addWidget(tBtn, 4 , 3);
    layout->addWidget(dBtn, 5 , 3);
    layout->addWidget(eBtn, 6 , 3);
    addBtn->setMinimumHeight(60);
    subBtn->setMinimumHeight(60);
    tBtn->setMinimumHeight(60);
    dBtn->setMinimumHeight(60);
    eBtn->setMinimumHeight(60);


    //connect(eBtn, &QPushButton::clicked,this, &Calculator::Calculate);

    //加法
    connect(addBtn, &QPushButton::clicked, this, [this]() {
        operation = '+';
        FunCalculate(operation);

    });

    //等於
    connect(eBtn, &QPushButton::clicked, this, [this]() {
        operation = '=';
        FunCalculate(operation);

    });

}

void Calculator::Calculate() {
    secondNum = display->text().toDouble();

    double result = 0;

    switch (operation.toLatin1()) {
    case '+':
        result = firstNum + secondNum;
        break;
    case '-':
        result = firstNum - secondNum;
        break;
    case '*':
        result = firstNum * secondNum;
        break;
    case '/':
        if (secondNum == 0) {
            display->setText("Error");
            return;
        }
        result = firstNum / secondNum;
        break;
    default:
        return;
    }

    display->setText(QString::number(result));
    QString refun;
    refun = QString::number(firstNum) + operation.toLatin1() + QString::number(secondNum) + "=";
    this->funDisplay->setText(refun);
}

void Calculator::FunCalculate(const QChar& operation) {
    this->firstNum = display->text().toDouble();
    if (this->newInput) {
        this->Calculate();
    }

    QString refun;
    refun = QString::number(firstNum) + operation.toLatin1();
    this->funDisplay->setText(refun);
    this->newInput = operation.toLatin1() == '=' ? true : false ;
}


Calculator::~Calculator() = default;
