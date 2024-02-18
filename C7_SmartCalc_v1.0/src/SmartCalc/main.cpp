#include <QApplication>

#include "CalcWindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  defoltwindow w;
  w.show();
  return a.exec();
}
