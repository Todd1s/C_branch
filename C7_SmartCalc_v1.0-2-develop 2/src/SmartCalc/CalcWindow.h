#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <Graph.h>

#include <QDialog>

extern "C" {
#include "SmartCalcMain.h"
}

namespace Ui {
class defoltwindow;
}

class defoltwindow : public QDialog {
  Q_OBJECT

 public:
  explicit defoltwindow(QWidget *parent = nullptr);
  ~defoltwindow();

 signals:
  void firstWindow();
  void signalBase(QString, QString, QString, QString, QString);

 private slots:
  void digit_numbers();
  void math_operations();
  void functions();
  void on_delete_2_clicked();
  void on_ButtonPoint_clicked();
  void pushString();
  void on_but_X_clicked();
  void on_graf_clicked();

 private:
  Ui::defoltwindow *ui;
  Form *form;
};

#endif  // CALCWINDOW_H
