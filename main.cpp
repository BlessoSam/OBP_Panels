#include "obp_panels.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OBP_Panels w;
    w.show();
    return a.exec();
}
