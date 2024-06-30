#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTime>
#include <QTimer>
#include <QDebug>

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
    void timeout();
    void start();
    void stop();


private:
    Ui::Dialog *ui;

    QTimer m_timer;
    QTime m_started;
    QTime m_stopped;

};
#endif // DIALOG_H
