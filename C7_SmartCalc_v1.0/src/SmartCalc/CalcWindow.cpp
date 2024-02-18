#include "CalcWindow.h"

#include "ui_CalcWindow.h"

defoltwindow::defoltwindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::defoltwindow)

{
  defoltwindow::setFixedSize(421, 461);
  ui->setupUi(this);

  form = new Form();
  connect(this, &defoltwindow::signalBase, form,
          &Form::slot);  // для передачи инфы
  connect(form, &Form::signal, this,
          &defoltwindow::show);  // скрываю ненужные окна

  connect(ui->num_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->num_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->plus, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->minus, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->division, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->mult, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->Button_Pow, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->Button_Mod, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->Button_Sqrt, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Log, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->Button_Point, SIGNAL(clicked()), this,
          SLOT(on_ButtonPoint_clicked()));
  connect(ui->Button_LeftBracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->Button_RightBracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->result, SIGNAL(clicked()), this, SLOT(pushString()));
}

defoltwindow::~defoltwindow() { delete ui; }

void defoltwindow::digit_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_number->text() + button->text();
  ui->result_number->setText(new_label);
}

void defoltwindow::math_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->result_number->text();
  if (button->text() == "/" && !(ui->result_number->text().endsWith("/"))) {
    new_label += "/";
  } else if (button->text() == "*" &&
             !(ui->result_number->text().endsWith("*"))) {
    new_label += "*";
  } else if (button->text() == "+" &&
             !(ui->result_number->text().endsWith("+"))) {
    new_label += "+";
  } else if (button->text() == "-" &&
             !(ui->result_number->text().endsWith("-"))) {
    new_label += "-";
  } else if (button->text() == "pow" &&
             !(ui->result_number->text().endsWith("^"))) {
    new_label += "^";
  } else if (button->text() == "mod" &&
             !(ui->result_number->text().endsWith("%"))) {
    new_label += "%";
  } else if (button->text() == "(") {
    new_label += "(";
  } else if (button->text() == ")") {
    new_label += ")";
  }
  ui->result_number->setText(new_label);
}

void defoltwindow::functions() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_number->setText(ui->result_number->text() + button->text() + "(");
}

void defoltwindow::on_delete_2_clicked() { ui->result_number->setText(""); }

void defoltwindow::on_ButtonPoint_clicked() {
  if (!(ui->result_number->text().endsWith('.')))
    ui->result_number->setText(ui->result_number->text() + ".");
}

void defoltwindow::pushString() {
  std::string str = ui->result_number->text().toStdString();
  char *expression = &str[0];
  std::string str_sum = ui->result_x->text().toStdString();
  char *sum = &str_sum[0];
  double resX = atof(sum);
  double res = 0.0;
  start(expression, &res, resX);
  QString num1 = QString::number(res, 'f', 6);
  ui->result_number->setText(num1);
}

void defoltwindow::on_but_X_clicked() {
  if (!(ui->result_number->text().endsWith("x")))
    ui->result_number->setText(ui->result_number->text() + "x");
}

void defoltwindow::on_graf_clicked() {
  emit signalBase(ui->result_number->text(), ui->result_x_2->text(),
                  ui->result_x_3->text(), ui->result_x_4->text(),
                  ui->result_x_5->text());
  form->show();  // Показываем второе окно
  this->close();
}
