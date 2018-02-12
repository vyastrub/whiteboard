#include "penbar.hpp"

penBar::penBar(QWidget *parent) : QHBoxLayout()
{
    Q_UNUSED(parent);

    label1 = new QLabel("Pen color:");
    label2 = new QLabel("Pen Size:");
    cur_col = new QToolButton;
    spinBox = new QSpinBox;
    slider = new QSlider(Qt::Horizontal);
    grid_layout = new QGridLayout;
    signal_mapper = new QSignalMapper(this);
    spacer = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QColor arr[16]= {Qt::black, Qt::lightGray, Qt::darkBlue, Qt::darkCyan,
                    Qt::darkGreen, Qt::darkYellow, Qt::darkRed,
                    Qt::darkMagenta, Qt::gray, Qt::white, Qt::blue,
                    Qt::cyan, Qt::green, Qt::yellow, Qt::red, Qt::magenta};

    for (int i = 0; i < 16; i++)
    {
        toolButton[i] = new ColorButton(arr[i]);
        grid_layout->addWidget(toolButton[i], i / 8, i % 8);
        connect(toolButton[i], SIGNAL(clicked(bool)), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(toolButton[i], i);
    }

    QPixmap bg(40, 40);
    bg.fill(Qt::black);
    cur_col->setFixedSize(40,40);
    cur_col->setIcon(bg);
    cur_col->setIconSize(QSize(40,40));
    spinBox->setMinimum(1);
    spinBox->setMaximum(10);
    spinBox->setValue(1);
    slider->setFixedSize(150, 40);
    slider->setMinimum(1);
    slider->setMaximum(10);
    slider->setSingleStep(1);
    slider->setPageStep(1);
    slider->setSliderPosition(1);
    grid_layout->setSpacing(0);
    setSpacing(5);
    addWidget(label1);
    addWidget(cur_col);
    addLayout(grid_layout);
    addWidget(label2);
    addWidget(slider);
    addWidget(spinBox);
    addItem(spacer);
}

penBar::~penBar()
{
    for (int i = 0; i < 16; i++)
        delete toolButton[i];
}
