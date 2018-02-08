#ifndef COLORBUTTON_HPP
#define COLORBUTTON_HPP

#include "whiteboard.hpp"

class ColorButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ColorButton(QToolButton *parent = nullptr);
    ColorButton(QColor color);
    ~ColorButton();
    QColor get_color() const;

private:
    QColor  _color;

signals:


public slots:
};

#endif // COLORBUTTON_HPP
