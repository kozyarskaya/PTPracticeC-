#include "deleteform.h"
#include "ui_deleteform.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDate>

DeleteForm::DeleteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteForm)
{
    ui->setupUi(this);
    ui->lineEditYear->setInputMask("d999;_");
    ui->lineEditNum->setInputMask("9999 >AA 99;_");
    ui->lineEditYear->clear();
    ui->lineEditYear->setCursorPosition(0);
}

DeleteForm::~DeleteForm()
{
    delete ui;
}


void DeleteForm::on_bntDelete_clicked()
{
   int ki = 0;
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
   if ((ui->lineEditNum->text()=="") && ((ui->lineEditSurn->text()!="" ||
                                          ui->lineEditYear->text()!="" ||
                                          ui->lineEditMarka->text()!=""))){
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this,"Внимание", "Будут удалены все мотоциклы, удовлетворяющие данным параметрам. Для конкретики необходимо ввести госномер номер. Продолжить?",
                                 QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes){
               ki = 1;
           }
         else{
               ui->lineEditNum->clear();
               ui->lineEditSurn->clear();
               ui->lineEditYear->clear();
               ui->lineEditMarka->clear();
           }
    }
    if(ui->lineEditNum->text()!="") ki=1;
    if(ki == 1){
        QFile file("motopark.txt");
        QFile file2("motopark2.txt");
        QTextStream in(&file);
        if (file.open(QIODevice::ReadOnly)) {
                bool found = false;
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    QStringList list = line.split(" ");
                    if(!((list[0] == ui->lineEditMarka->text() || ui->lineEditMarka->text() == "") &&
                         (list[1] == ui->lineEditYear->text() || ui->lineEditYear->text() == "") &&
                         (list[2] == ui->lineEditNum->text() || ui->lineEditNum->text() == "") &&
                         (list[3] == ui->lineEditSurn->text() || ui->lineEditSurn->text() == ""))){
                        QFile file2("motopark2.txt");
                        if(file2.open(QIODevice::Append)) {
                           QTextStream out(&file2);
                           out <<list[0]<<":"<<list[1]<<":"<<list[2]<<":"<< list[3] << "\n";
                        }
                    }
                    else{
                         found = true;
                   }
        }
        if (!found) {
            QMessageBox::information(this,"Ошибка","Данные не найдены");
        }

        else{QMessageBox::information(this,"Успех","Данные успешно удалены");
            ui->lineEditNum->clear();
            ui->lineEditSurn->clear();
            ui->lineEditYear->clear();
            ui->lineEditMarka->clear();
        }
        file.close();
        file2.close();
        remove("motopark.txt");
        rename("motopark2.txt", "motopark.txt");
        }
    }
}
