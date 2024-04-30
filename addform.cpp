#include "addform.h"
#include "ui_addform.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QDebug>
#include <QDate>
#include <QFile>

AddForm::AddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    ui->setupUi(this);
    ui->lineEditYear->setInputMask("d999;_");
    ui->lineEditNum->setInputMask("9999 >AA 99;_");
    ui->lineEditYear->clear();
    ui->lineEditYear->setCursorPosition(0);
    connect(ui->btnAdd,SIGNAL(clicked(bool)),this,SLOT(onBtnAdd()));
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::onBtnAdd(){
    if(ui->lineEditNum->text() == "" || ui->lineEditSurn->text() == "" ||
            ui->lineEditYear->text() == "" || ui->lineEditMarka->text() == ""){
        QMessageBox::warning(this, "Ошибка", "Заполнены не все поля");
        return;
    }
    QDate date = QDate::currentDate();
    if(ui->lineEditYear->text().toInt() > date.year()){
        QMessageBox::warning(this, "Ошибка", "Ваш Мотоцикл произведен в будущем, пожалуйста введите корректный год производства");
        ui->lineEditYear->clear();
        ui->lineEditYear->setFocus();
        return;
    }

    QFile file("motopark.txt");
    if(file.open(QIODevice::Append)){
        QString sur = ui->lineEditSurn->text();
        sur = sur [0].toUpper () + sur.mid (1, sur.size () - 1).toLower();
        QTextStream out(&file);
        out << ui->lineEditMarka->text() << ":" << ui->lineEditYear->text() << ":" <<
               ui->lineEditNum->text() << ":" << sur << '\n';
    }
    ui->lineEditNum->clear();
    ui->lineEditSurn->clear();
    ui->lineEditYear->clear();
    ui->lineEditMarka->clear();
    ui->lineEditMarka->setFocus();

    file.close();


}

void AddForm::on_btnInfo_clicked()
{
     QMessageBox::information(this, "Пример заполнения полей",
                              "Марка:  BMW R 1100 GS\nГод выпуска:  1997\nГосномер:  2356 DF 23\nФамилия владельца:  Петров\n");
     return;
}
