#include "scene.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(), pos(0), step_count(0),
    _current_color(Qt::black), _size(1), _pressed(false)
{
    Q_UNUSED(parent);

    this->view = new QGraphicsView;
    view->setMinimumSize(1024, 526);
    view->setScene(this);
    setSceneRect(0,0, view->width(), view->height());
    step.append(0);

}

void Scene::set_color(QColor const color)
{
    this->_current_color = color;
}

void Scene::set_size(int const size)
{
    this->_size = size;
}

void Scene::set_shape(int const flag)
{
    this->_shape_flag = flag;
}

void Scene::renew_buffer()
{
    int i = pos - 1;
    while (i >= step.value(step_count))
    {
        delete items.at(i);
        items.removeAt(i);
        i--;
    }
    i = step.size() - 1;
    while (i > step_count)
    {
        step.removeAt(i);
        i--;
    }
    pos = step.value(step_count);
}

Scene::~Scene()
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if (step_count < step.size() - 1)
        {
            renew_buffer();
        }
        this->_start = event->scenePos();
        this->_pressed = true;
        if (_shape_flag != 1)
        {
            items.append(new Item(_start, event->scenePos(), _current_color, _size, _shape_flag));
            addItem(items.at(pos));
        }
        update();
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (_pressed)
    {
        if (_shape_flag == 1)
        {
            items.append(new Item(_start, event->scenePos(), _current_color, _size, _shape_flag));
            addItem(items.at(pos++));
            _start = event->scenePos();
        }
        else
        {
            removeItem(items.at(pos));
            delete items.at(pos);
            items.removeAt(pos);
            items.append(new Item(_start, event->scenePos(), _current_color, _size, _shape_flag));
            addItem(items.at(pos));
        }
    }
    update();

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if (_shape_flag != 1)
        {
            pos++;
        }
        step.append(pos);
        step_count++;
        this->_pressed = false;
        update();
    }
}

void Scene::clear_scene()
{
    qDeleteAll(items);
    items.clear();
    step.clear();
    step.append(0);
    pos = 0;
    step_count = 0;
    clear();
    update();
}

void Scene::undo()
{
    int last_step = step.value(step_count);
    int i = step.value(step_count - 1);

    while (i < last_step)
    {
        removeItem(items.at(i));
        i++;
    }
    update();
    if (step_count > 0)
        step_count--;
}

void Scene::redo()
{
    int i = step.value(step_count);
    int last_step = step.value(step_count + 1);

    while (i < last_step)
    {
        addItem(items.at(i));
        i++;
    }
    update();
    if (step_count < step.size() - 1)
        step_count++;
}