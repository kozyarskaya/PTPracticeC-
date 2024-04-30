#include "findform.h"
#include "ui_findform.h"
#include <QButtonGroup>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>



findForm::findForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findForm)
{
    ui->setupUi(this);

    QButtonGroup *group = new QButtonGroup;
    group->addButton(ui->rbtnMarka);
    group->addButton(ui->rbtnSurn);
    group->addButton(ui->rbtnYear);

    ui->lineEdit->setEnabled(false);
    ui->label->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->btnSearch->setEnabled(false);


}

findForm::~findForm()
{
    delete ui;
}

void findForm::on_rbtnMarka_clicked(bool checked)
{
    if(checked){
        ui->label->setText("Введите марку:");
        ui->label_2->setText("Показывает алфавитный перечень владельцев, имеющих мотоциклы данной марки.");
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->btnSearch->setEnabled(true);
        ui->lineEdit->clear();
        ui->textEdit->clear();
        ui->lineEdit->setFocus();
    }
}

void findForm::on_rbtnSurn_clicked(bool checked)
{
    if(checked){
        ui->label->setText("Введите фамилию владельца:");
        ui->label_2->setText("Определяет марки и госномера мотоциклов, принадлежащих данному владельцу.");
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->btnSearch->setEnabled(true);
        ui->lineEdit->clear();
        ui->textEdit->clear();
        ui->lineEdit->setFocus();
    }
}

void findForm::on_rbtnYear_clicked(bool checked)
{
    if(checked){
        ui->label->setText("Введите год:");
        ui->label_2->setText("Определяет фамилии владельцев, марки и госномера мотоциклов не старше данного года выпуска.");
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->btnSearch->setEnabled(true);
        ui->lineEdit->clear();
        ui->textEdit->clear();
        ui->lineEdit->setFocus();
    }
}

void findForm::showResults(QStringList list, QString str, int k){
    ui->textEdit->clear();
    ui->textEdit->isReadOnly();
    ui->lineEdit->isReadOnly();
    ui->lineEdit->setText(str);
    for(int i = 0; i < k; i++){
        ui->textEdit->append(list[i]);
    }
}

void findForm::showFIO(){
    QString mark = ui->lineEdit->text();
    QStringList itog;

    QFile file ("motopark.txt");
    QTextStream in(&file);
    int kol = 0;
    if (file.open(QIODevice::ReadOnly)){
        bool found = false;
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(" ");
            if(list[0] == mark){
                found = true;
                bool initog = false;
                for(int i = 0; i < kol; i++){
                    if (itog[i] == list[3])
                        initog = 1;
                }
                if(initog == 0){
                    itog.append(list[3]);
                    kol++;
                }
            }
        }
        if(!found){
            QMessageBox::information(this,"Ошибка","Данные не найдены");
        }
        else{
            itog.sort();
            showResults(itog, mark, kol);
            ui->lineEdit->clear();
            ui->lineEdit->setFocus();
        }
        file.close();
    }

}

void findForm::showMarkNum(){
    QString fio = ui->lineEdit->text();
    QStringList itog;
    QFile file ("motopark.txt");
    QTextStream in(&file);
    int kol = 0;
    if (file.open(QIODevice::ReadOnly)){
        bool found = false;
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(" ");
            if(list[3] == fio){
                found = true;
                itog.append("марка - " + list[0] + ", госномер " + list[2]);
                kol++;
            }
        }
        if(!found){
            QMessageBox::information(this,"Ошибка","Данные не найдены");
        }
        else{
            itog.sort();
            showResults(itog, fio, kol);
            ui->lineEdit->clear();
            ui->lineEdit->setFocus();
        }
        file.close();
    }


}

void findForm::showFIOMarkNum(){
    QString year = ui->lineEdit->text();
    QStringList itog;
    QFile file ("motopark.txt");
    QTextStream in(&file);
    int kol = 0;
    if (file.open(QIODevice::ReadOnly)){
        bool found = false;
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(" ");
            if(list[1] <= year){
                found = true;
                itog.append(list[3] + ": марка - " + list[0] + ", госномер "
                        + list[2] + ", " + list[1]);
                kol++;
            }
        }
        if(!found){
            QMessageBox::information(this,"Ошибка","Данные не найдены");
        }
        else{
            itog.sort();
            showResults(itog, year, kol);
            ui->lineEdit->clear();
            ui->lineEdit->setFocus();
        }
        file.close();
    }

}


void findForm::on_btnSearch_clicked()
{
    if(ui->rbtnMarka->isChecked()) showFIO();
    if(ui->rbtnSurn->isChecked()) showMarkNum();
    if(ui->rbtnYear->isChecked()) showFIOMarkNum();
}
