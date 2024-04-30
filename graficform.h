#ifndef GRAFICFORM_H
#define GRAFICFORM_H

#include <QWidget>
#include "qcustomplot.h"
#include<QVector>

namespace Ui {
class GraficForm;
}

class GraficForm : public QWidget
{
    Q_OBJECT

public:
    explicit GraficForm(QWidget *parent = nullptr);
    ~GraficForm();

    void printGraf();

private:
    Ui::GraficForm *ui;



};

#endif // GRAFICFORM_H
