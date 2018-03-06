#include "colorbutton.hpp"

ColorButton::ColorButton(QToolButton *parent) : QToolButton(parent)
{

}

ColorButton::ColorButton(QColor color) : _color(color)
{
    setFixedSize(20,20);
    QPixmap bg(20, 20);
    bg.fill(color);
    setIcon(bg);
}

ColorButton::~ColorButton()
{

}

QColor ColorButton::get_color() const
{
    return _color;
}
