#ifndef SCENE_HPP
#define SCENE_HPP

#include "item.hpp"

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit    Scene(QObject *parent = nullptr);
    void        set_color(QColor const color);
    void        set_size(int const size);
    void        set_shape(int const flag);
    void        renew_buffer();
    ~Scene();

    QGraphicsView *view;
    int           pos;
    int           step_count;
    QList<int>    step;

private:

    QPointF       _start;
    QColor        _current_color;
    int           _size;
    int           _shape_flag;
    bool          _pressed;
    QList<Item *> items;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:

private slots:

    void clear_scene();
    void undo();
    void redo();
};

#endif // SCENE_HPP
