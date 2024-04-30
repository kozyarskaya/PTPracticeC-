#ifndef DELETEFORM_H
#define DELETEFORM_H

#include <QWidget>

namespace Ui {
class DeleteForm;
}

class DeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteForm(QWidget *parent = nullptr);
    ~DeleteForm();

private slots:
    void on_bntDelete_clicked();

private:
    Ui::DeleteForm *ui;
};

#endif // DELETEFORM_H
