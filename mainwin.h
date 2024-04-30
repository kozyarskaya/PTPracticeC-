#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include "addform.h"
#include "findform.h"
#include "printform.h"
#include "deleteform.h"
#include "graficform.h"
#include<QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT


public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void showAdd();
    void showPrint();
    void showFind();
    void showDelete();
    void showGrafic();

private:
    Ui::MainWin *ui;
    AddForm *winAdd;
    findForm *winFind;
    PrintForm *winPrint;
    DeleteForm *winDelete;
    GraficForm *winGrafic;

};
#endif // MAINWIN_H
