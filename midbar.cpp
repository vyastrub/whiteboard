#include "midbar.hpp"

midBar::midBar(QWidget *parent) : QHBoxLayout()
{
    Q_UNUSED(parent);

    label = new QLabel("Shape Type:");
    button1 = new QPushButton("Undo");
    button2 = new QPushButton("Redo");
    button3 = new QPushButton("Cleanup");
    comboBox = new QComboBox;
    spacer = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    comboBox->addItem("Line");
    comboBox->addItem("Curve");
    comboBox->addItem("Rectangle");
    comboBox->addItem("Ellipse");
    button1->setEnabled(false);
    button2->setEnabled(false);
    button3->setEnabled(false);
    setSpacing(5);
    addWidget(label);
    addWidget(comboBox);
    addWidget(button1);
    addWidget(button2);
    addWidget(button3);
    addItem(spacer);
}

midBar::~midBar()
{

}
