#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QClipboard>

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
    void on_treeWidget_itemExpanded(QTreeWidgetItem *item);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;

    void addRoots();
    QTreeWidgetItem *createItem(QFileInfo fi);
    void addExpander(QTreeWidgetItem *root);
    void addChildren(QTreeWidgetItem *root);
    void setCheckState(QTreeWidgetItem *root, Qt::CheckState state);
    void getCheckedItems(QTreeWidgetItem *root);
    void getCheckedItems();
};
#endif // DIALOG_H
