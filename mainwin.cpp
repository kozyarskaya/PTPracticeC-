#include "mainwin.h"
#include "ui_mainwin.h"
#include "QVBoxLayout"
#include<QWidget>

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);
    winAdd = new AddForm;
    winFind = new findForm;
    winPrint = new PrintForm;
    winDelete = new DeleteForm;
    winGrafic = new GraficForm;

    connect(ui->btnAdd,SIGNAL(clicked(bool)),this,SLOT(showAdd()));
    connect(ui->btnSearch,SIGNAL(clicked(bool)),this,SLOT(showFind()));
    connect(ui->btnPrintAll, SIGNAL(clicked(bool)),this,SLOT(showPrint()));
    connect(ui->btnDelete, SIGNAL(clicked(bool)),this,SLOT(showDelete()));
    connect(ui->btnStatictics, SIGNAL(clicked(bool)),this,SLOT(showGrafic()));
};


MainWin::~MainWin()
{
    delete ui;
}

void MainWin::showAdd(){
    winAdd->show();
}

void MainWin::showFind(){
    winFind->show();
}

void MainWin::showPrint(){
    winPrint->show();
}

void MainWin::showDelete(){
    winDelete->show();
}

void MainWin::showGrafic(){
    winGrafic->show();

}




