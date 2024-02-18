#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QWidget>
#include <QtMath>

extern "C" {
#include "SmartCalcMain.h"
}

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

 public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

 signals:
  void signal();

 private:
  Ui::Form *ui;

 public slots:
  void slot(QString a, QString Xmin, QString Xmax, QString Ymin, QString Ymax);

 private slots:
  void on_pushButton_clicked();
};

#endif  // GRAPH_H
