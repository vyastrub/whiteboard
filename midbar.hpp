#ifndef MIDBAR_HPP
#define MIDBAR_HPP

#include "whiteboard.hpp"

class midBar : public QHBoxLayout
{
    Q_OBJECT

public:
    explicit midBar(QWidget *parent = nullptr);
    ~midBar();
    QComboBox   *comboBox;
    QPushButton *button3;
    QPushButton *button1;
    QPushButton *button2;

private:

    QLabel      *label;
    QSpacerItem *spacer;

signals:

public slots:
};

#endif // MIDBAR_HPP
