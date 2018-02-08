#ifndef FORM_H
#define FORM_H

#include "scene.hpp"
#include "penbar.hpp"
#include "midbar.hpp"

class Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
     QWidget & get_win() const;
     void connecting();

private:

    QWidget     *win;
    penBar      *pen_bar;
    midBar      *middle_bar;
    Scene       *scene;
    QVBoxLayout *vertical_layout;

signals:

private slots:

    void change_color(int i);
    void change_size(int s);
    void change_shape(int flag);
    void enable_manager();
};

#endif // FORM_H
