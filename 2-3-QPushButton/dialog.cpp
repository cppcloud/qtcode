#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->btnCheckable->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheckable_clicked()
{
    qDebug() << "Checked: " << ui->btnCheckable->isChecked();
}

void Dialog::on_btnAutoRepeat_clicked()
{
    qInfo() << "Clicked";
}

void Dialog::on_btnDefault_clicked()
{
    qInfo() << "Default button clicked!";

}

void Dialog::on_btnIsChecked_clicked()
{
    QString message;
    if(ui->btnCheckable->isChecked())
    {
        message = "Yes it is checked";
    }
    else
    {
        message = "No it is not checked";
    }

    QMessageBox::information(this,"Checked", message);
}

void Dialog::on_btnToggleAutoRepeat_clicked()
{
    bool value = !ui->btnAutoRepeat->autoRepeat();

    ui->btnAutoRepeat->setAutoRepeat(value);
    qDebug() << "Repeat: " << ui->btnAutoRepeat->autoRepeat();
}

void Dialog::on_btnToggleDefault_clicked()
{
    bool value = !ui->btnDefault->isDefault();

    ui->btnDefault->setDefault(value);
    qDebug() << "Repeat: " << ui->btnDefault->isDefault();
}

void Dialog::on_btnQuit_clicked()
{
    accept();
}
