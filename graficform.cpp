#include "graficform.h"
#include "ui_graficform.h"
#include<QVector>
#include<QString>
#include<QFile>
#include<QTextStream>





GraficForm::GraficForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraficForm)
{
    ui->setupUi(this);

    double minYear = 2100, maxYear = -1, h, X, N;
    QVector<double> x, y, x2;

    QFile file ("motopark.txt");
    QTextStream in(&file);
    double maxi = 0;
        if (file.open(QIODevice::ReadOnly)){
            while(!in.atEnd()){
                QString line = in.readLine();
                QStringList list = line.split(":");
                if(list[1].toInt() > maxYear)
                    maxYear = list[1].toInt();
                if(list[1].toInt() < minYear)
                    minYear = list[1].toInt();
                //if(!x.contains(list[1].toInt())){
                     //x.push_back(list[1].toInt());}
                x2.push_back(list[1].toInt());
                }
            for(int i = minYear; i < maxYear;i++){
                int kol = x2.count(i);
                x.push_back(i);
                y.push_back(kol);
                if(kol > maxi)
                    maxi = kol;
            }

            }


    //оси
    ui->widget->xAxis->setRange(minYear-10, maxYear);
    ui->widget->yAxis->setRange(0, maxi + 2);
    ui->widget->xAxis->setLabel("Год");
    ui->widget->yAxis->setLabel("Кол-во");

   //стрелки на осях
    ui->widget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->widget->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);




    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();

    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag,true);


    file.close();


}


GraficForm::~GraficForm()
{
    delete ui;
}
