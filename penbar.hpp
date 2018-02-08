#ifndef PENBAR_HPP
#define PENBAR_HPP

#include "colorbutton.hpp"

class penBar : public QHBoxLayout
{
    Q_OBJECT
public:
    explicit penBar(QWidget *parent = nullptr);
    ~penBar();

    QSignalMapper   *signal_mapper;
    QToolButton     *cur_col;
    ColorButton     *toolButton[16];
    QSlider         *slider;
    QSpinBox        *spinBox;

private:

    QLabel          *label1;
    QLabel          *label2;
    QSpacerItem     *spacer;
    QGridLayout     *grid_layout;

signals:

public slots:
};

#endif // PENBAR_HPP
