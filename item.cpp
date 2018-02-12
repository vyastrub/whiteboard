#include "item.hpp"

Item::Item(QPointF start, QPointF end, QColor color, int size, int figure_flag)
{
    _x = start.x();
    _y = start.y();
    _w = end.x() - _x;
    _h = end.y() - _y;
    _start = start;
    _finish = end;
    _color = color;
    _size = size;
    _shape = figure_flag;
}

Item::~Item()
{

}

QRectF Item::boundingRect() const
{
    return QRectF(_x, _y, _w, _h);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem  *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(_color, _size);
    QRectF coord = boundingRect();
    painter->setPen(pen);

    if (_shape == 0)
    {
        painter->drawLine(_start, _finish);
    }
    else if (_shape == 1)
    {
        if (_start != _finish)
        {
            painter->drawLine(_start, _finish);
        }
        else
        {
            painter->drawPoint(_start);
        }
    }
    else if (_shape == 2)
    {
        painter->drawRect(coord);
    }
    else if (_shape == 3)
    {
        painter->drawEllipse(coord);
    }
}
