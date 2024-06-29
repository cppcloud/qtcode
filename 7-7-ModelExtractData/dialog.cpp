#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    for (int i = 0;i < 5;i++)
    {
        model.appendRow(new QStandardItem(QString("Item %0").arg(i)));
    }
    ui->listView->setModel(&model);
}


void Dialog::on_buttonBox_accepted()
{
    QStringList list;

    for (int i = 0;i < model.rowCount();i++)
    {
        QStandardItem *item = model.item(i);
        list.append(item->text());
    }

    QString msg = list.join("\r\n");
    QMessageBox::information(this,"Items", msg);

    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

