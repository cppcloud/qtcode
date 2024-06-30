#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    foreach (QScreen *screen, QGuiApplication::screens())
    {
        ui->cmbScreens->addItem(screen->name());
    }

    ui->btnSave->setEnabled(false);
    ui->lblScreen->setText("");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnScreen_clicked()
{
    QScreen *screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());
    if(!screen)
    {
        QMessageBox::critical(this,"Error","Could not get the screen!");
        return;
    }

    hide();
    QTimer::singleShot(500, this,&Dialog::shoot);

}

void Dialog::on_btnSave_clicked()
{
    QString path  = QFileDialog::getSaveFileName(this,"Save",QString(),"PNG Image (*.png)");
    if(path.isEmpty()) return;

    QFileInfo fi(path);
    if(fi.exists())
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this,"Exist","File already exists would you like to overwrite it?");
        if(btn != QMessageBox::StandardButton::Yes) return;
    }

    if(!m_image.save(path,"PNG"))
    {
        QMessageBox::critical(this,"Error","Could not save image!");
    }
}

void Dialog::shoot()
{
    //Restricted on some OS
    //https://doc.qt.io/qt-5/qscreen.html#grabWindow

    QScreen *screen = QGuiApplication::screens().at(ui->cmbScreens->currentIndex());

    m_image = screen->grabWindow(0);

    QPixmap m_scaled = m_image.scaled(ui->lblScreen->width(),ui->lblScreen->height(),Qt::AspectRatioMode::KeepAspectRatio);

    ui->lblScreen->setPixmap(m_scaled);
    ui->btnSave->setEnabled(true);
    show();

}







