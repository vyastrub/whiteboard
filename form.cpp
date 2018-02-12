#include "form.hpp"

Form::Form(QWidget *parent) : QWidget(parent)
{
    this->pen_bar = new penBar;
    this->middle_bar = new midBar;
    this->scene = new Scene;
    this->vertical_layout = new QVBoxLayout;
    vertical_layout->setSpacing(5);
    vertical_layout->addLayout(pen_bar);
    vertical_layout->addLayout(middle_bar);
    vertical_layout->addWidget(scene->view);
    setWindowTitle("whiteboard");
    setLayout(vertical_layout);
}

Form::~Form()
{
    delete pen_bar;
    delete middle_bar;
    delete scene;
}

void Form::connecting()
{
    connect(pen_bar->signal_mapper, SIGNAL(mapped(int)),
            this, SLOT(change_color(int)));
    connect(pen_bar->slider,SIGNAL(valueChanged(int)),
            pen_bar->spinBox, SLOT(setValue(int)));
    connect(pen_bar->slider,SIGNAL(valueChanged(int)),
            this, SLOT(change_size(int)));
    connect(pen_bar->spinBox, SIGNAL(valueChanged(int)),
            pen_bar->slider, SLOT(setValue(int)));
    connect(pen_bar->spinBox, SIGNAL(valueChanged(int)),
            this, SLOT(change_size(int)));
    connect(middle_bar->comboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(change_shape(int)));
    connect(middle_bar->button3, SIGNAL(clicked(bool)),
            scene, SLOT(clear_scene()));
    connect(middle_bar->button1, SIGNAL(clicked(bool)),
            scene, SLOT(undo()));
    connect(middle_bar->button2, SIGNAL(clicked(bool)),
            scene, SLOT(redo()));
    connect(middle_bar->button3, SIGNAL(clicked(bool)),
            this, SLOT(enable_manager()));
    connect(middle_bar->button1, SIGNAL(clicked(bool)),
             this, SLOT(enable_manager()));
    connect(middle_bar->button2, SIGNAL(clicked(bool)),
            this, SLOT(enable_manager()));
    connect(scene, SIGNAL(changed(QList<QRectF>)),
            this, SLOT(enable_manager()));
}

void Form::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    scene->setSceneRect(-scene->view->width() / 2, - scene->view->height() / 2 , scene->view->width(), scene->view->height());
}

void Form::change_color(int i)
{
    QColor tmp = pen_bar->toolButton[i]->get_color();

    QPixmap bg(40, 40);
    bg.fill(tmp);
    pen_bar->cur_col->setIcon(bg);
    scene->set_color(tmp);
}

void Form::change_size(int s)
{
    scene->set_size(s);
}

void Form::change_shape(int flag)
{
    scene->set_shape(flag);
}

void Form::enable_manager()
{
    if (scene->step_count < 1)
    {
        middle_bar->button1->setEnabled(false);
        middle_bar->button3->setEnabled(false);
    }
    else
    {
        middle_bar->button1->setEnabled(true);
        middle_bar->button3->setEnabled(true);
    }
    if (scene->step_count == scene->step.size() - 1)
    {
         middle_bar->button2->setEnabled(false);
    }
    else
    {
        middle_bar->button2->setEnabled(true);
    }
}



