#ifndef PRINTFORM_H
#define PRINTFORM_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class PrintForm;
}

class PrintForm : public QWidget
{
    Q_OBJECT
    QTableWidget *table;
public:
    explicit PrintForm(QWidget *parent = nullptr);
    ~PrintForm();

private slots:
    void on_btnUpdate_clicked();

private:
    Ui::PrintForm *ui;
};

#endif // PRINTFORM_H
