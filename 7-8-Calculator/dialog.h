#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "equation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void number();
    void update();
    void addEquation();

private:
    Ui::Dialog *ui;

    QList<Equation*> m_list;
    void init();
    Equation *getLast();
    void updateValue(QString data);
    void updateAction(Equation::Action value);

};
#endif // DIALOG_H
