#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QScreen>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>

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
    void on_btnScreen_clicked();
    void on_btnSave_clicked();
    void shoot();

private:
    Ui::Dialog *ui;
    QPixmap m_image;
    QTimer m_timer;

};
#endif // DIALOG_H
