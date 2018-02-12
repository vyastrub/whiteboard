#include "form.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Form a;
    a.connecting();
    a.show();
    return app.exec();
}
