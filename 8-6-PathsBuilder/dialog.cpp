#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    addRoots();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_treeWidget_itemExpanded(QTreeWidgetItem *item)
{
    addChildren(item);
}

void Dialog::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column)
    setCheckState(item,item->checkState(0));
    getCheckedItems();
}

void Dialog::on_buttonBox_accepted()
{
    //In case you want to update the checked items
    getCheckedItems();

    //copy to the clipboard
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->plainTextEdit->toPlainText());

    QMessageBox::information(this,"Copied","All information was copied to the clipboard!");

    //accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::addRoots()
{
    QFileInfoList drives = QDir::drives();
    ui->treeWidget->setHeaderHidden(true);

    foreach(QFileInfo fi, drives)
    {
        ui->treeWidget->addTopLevelItem(createItem(fi));
    }

    for (int i = 0;i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i);
        addChildren(item);
    }
}

QTreeWidgetItem *Dialog::createItem(QFileInfo fi)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    if(fi.fileName().isEmpty())
    {
        item->setText(0,fi.filePath());
    }
    else
    {
        item->setText(0,fi.fileName());
    }

    item->setCheckState(0,Qt::CheckState::Unchecked);
    item->setData(0,Qt::ItemDataRole::UserRole, fi.filePath());

    addExpander(item);

    return item;
}

void Dialog::addExpander(QTreeWidgetItem *root)
{
    if(root->childCount() > 0) return;
    QFileInfo fi(root->data(0,Qt::ItemDataRole::UserRole).toString());
    QDir dir(fi.filePath());
    QFileInfoList list = dir.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot);
    if(list.count() == 0) return;

    root->addChild(new QTreeWidgetItem(QStringList() << "Scanning.."));
}

void Dialog::addChildren(QTreeWidgetItem *root)
{
    if(root->childCount() > 1) return;
    QFileInfo rootInfo(root->data(0,Qt::ItemDataRole::UserRole).toString());
    if(!rootInfo.isDir()) return;

    //Remove Expander
    if(root->childCount() == 1)
    {
        QTreeWidgetItem *item = root->child(0);
        if(item->data(0,Qt::ItemDataRole::UserRole).isNull()) root->removeChild(item);
    }

    //Add Children
    QDir dir(rootInfo.filePath());
    QFileInfoList list = dir.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot);

    foreach(QFileInfo fi, list)
    {
        QTreeWidgetItem *item = createItem(fi);
        item->setCheckState(0,root->checkState(0));
        root->addChild(item);
    }
}

void Dialog::setCheckState(QTreeWidgetItem *root, Qt::CheckState state)
{
    root->setCheckState(0,state);
    for (int i = 0;i < root->childCount();i++)
    {
        QTreeWidgetItem *child = root->child(i);
        setCheckState(child,state);
    }
}

void Dialog::getCheckedItems()
{
    ui->plainTextEdit->clear();
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *root = ui->treeWidget->topLevelItem(i);
        getCheckedItems(root);
    }
}

void Dialog::getCheckedItems(QTreeWidgetItem *root)
{
    QString value = root->data(0,Qt::ItemDataRole::UserRole).toString();
    if(value.isEmpty()) return;

    if(root->checkState(0) == Qt::CheckState::Checked) ui->plainTextEdit->appendPlainText(value);

    for (int i = 0;i < root->childCount();i++)
    {
        QTreeWidgetItem *child = root->child(i);
        getCheckedItems(child);
    }
}











