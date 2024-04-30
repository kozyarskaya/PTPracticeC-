#ifndef FINDFORM_H
#define FINDFORM_H

#include <QWidget>

namespace Ui {
class findForm;
}

class findForm : public QWidget
{
    Q_OBJECT

public:
    explicit findForm(QWidget *parent = nullptr);
    ~findForm();

   void showFIO();
   void showMarkNum();
   void showFIOMarkNum();

private slots:
    void on_rbtnMarka_clicked(bool checked);

    void on_rbtnSurn_clicked(bool checked);

    void on_rbtnYear_clicked(bool checked);

    void showResults(QStringList list, QString, int);

    void on_btnSearch_clicked();

private:
    Ui::findForm *ui;
};

#endif // FINDFORM_H
