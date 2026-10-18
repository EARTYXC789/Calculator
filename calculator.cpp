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

    QLineEdit* funDisplay = new QLineEdit(this);
    funDisplay->setReadOnly(true);
    funDisplay->setAlignment(Qt::AlignRight);
    funDisplay->setMinimumHeight(30);
    layout->addWidget(funDisplay, 0, 0, 1, 6);

    QLineEdit* display = new QLineEdit(this);
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
            row = 5;
            col = 1;
        }
        else {
            row = (9 - i) / 3 + 2;
            col = (i - 1) % 3;
        }


        layout->addWidget(numBtnList[index], row, col);


        connect(numBtnList[index], &QPushButton::clicked, display, [display , i]() {display->setText(QString::number(i));});

    }

}

Calculator::~Calculator() = default;
