#include "printform.h"
#include "ui_printform.h"
#include <QFile>
#include <QTextStream>

PrintForm::PrintForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintForm)
{
    ui->setupUi(this);
}

PrintForm::~PrintForm()
{
    delete ui;
}


void PrintForm::on_btnUpdate_clicked()
{
    ui->textEdit->clear();
    QFile file ("motopark.txt");
        QTextStream in(&file);
        if (file.open(QIODevice::ReadOnly)){;
            while(!in.atEnd()){
                QString line = in.readLine();
                QStringList list = line.split(":");
                ui->textEdit->append(list[0] + '\t' + list[1] +
                        '\t' + list[2] + '\t' + list[3] + '\n');
                }
           }
        file.close();

}
