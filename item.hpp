#ifndef ITEM_HPP
#define ITEM_HPP

#include "whiteboard.hpp"

class Item : public QGraphicsItem
{
public:
    Item(QPointF const start, QPointF const end, QColor const color,
         int const size, int const figure_flag);
    ~Item();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    int     _x;
    int     _y;
    int     _w;
    int     _h;
    QPointF _start;
    QPointF _finish;
    QColor  _color;
    int     _size;
    int     _shape;
};

#endif // ITEM_HPP
