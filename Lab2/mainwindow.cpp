#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //int i = 0;
    for (QString colorname: english) {
        ui->colors->addItem(tr(colorname.toLatin1()));
        //ui->colorBox->setItemData(i++, QColor(colorname), Qt::DecorationRole);
        local.append(tr(colorname.toLatin1()));
    }
    QString eng("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    drawTree();
    for (auto letter: eng)
        ui->letters->insertItem(eng.length(), letter);
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->info->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawTree()
{
    //Перерисовка дерева
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->header()->setVisible(true);
    ui->treeWidget->headerItem()->setData(0, 0, "Key");
    ui->treeWidget->headerItem()->setData(1, 0, "Value");
    QTreeWidgetItem* item = new QTreeWidgetItem;
    item->setData(0, 0, "ROOT");
    item->setData(0, 0x100, 0);
    item->setFlags(Qt::ItemIsEnabled);
    ui->treeWidget->insertTopLevelItem(0, item);
    QVector<QString> vect;
    auto keys = tree.getKeys(vect);
    for (auto key: keys) {
        //Добавление ключа
        QTreeWidgetItem* t = item;
        for (int i = 0; i<key.size(); i++) {
            //Добавление элементов ключа
            if (t->text(1).isEmpty())
                t->setFlags(Qt::ItemIsEnabled);
            t->setExpanded(true);
            int child_number = t->childCount();
            for (int j = 0; j<t->childCount(); j++)
                //Поиск среди потомков
                if (t->child(j)->data(0, 0).toString() == key[i]) {
                    child_number = j;
                    break;
                }
            if (child_number == t->childCount()) {
                QTreeWidgetItem* key_item = new QTreeWidgetItem(t);
                key_item->setData(0, 0, key[i]);
                t->addChild(key_item);
            }
            int ind = local.indexOf(key[i]);
            if (ind != -1)
            t = t->child(child_number);
        }
        t->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        t->setData(1, 0, tree[key]);
        ui->deleteAll->setEnabled(true);
        ui->autoInsertKey->setEnabled(true);
    }
}
void MainWindow::drawKey(K &key)
{
    //Установка ключа
    on_clearSequence_clicked();
    auto curr = ui->colors->currentText();
    for (int i=0; i<key.size(); i++) {
        ui->colors->setCurrentText(key[i]);
        on_insertKey_clicked();
    }
    ui->colors->setCurrentText(curr);
    ui->info->setVisible(true);
}

void MainWindow::on_insertKey_clicked()
{
    //Добавление элемента ключа
    ui->info->setVisible(false);
    ui->listWidget->addItem(ui->colors->currentText());
    K key;
    for (int i = 0; i < ui->listWidget->count(); i++)
        key.push_back(ui->listWidget->item(i)->text());
    if (tree.checkHaveKey(key)) {
        //ui->iskey->setText("<font color='green'>✓</font>");
        ui->letters->setCurrentText(tree[key]);
    }
    else
        //ui->iskey->setText("<font color='red'>✕</font>");
    ui->clearSequence->setEnabled(true);
    ui->letters->setEnabled(true);
    ui->addTreeElement->setEnabled(true);
}

void MainWindow::on_clearSequence_clicked()
{
    //Очистить ключ
    ui->info->setVisible(false);
    ui->listWidget->clear();
    ui->clearSequence->setEnabled(false);
    ui->letters->setEnabled(false);
    ui->addTreeElement->setEnabled(false);
}

void MainWindow::on_autoInsertKey_clicked()
{
    K key;
    for (int i = 0; i < ui->listWidget->count(); i++)
        key.push_back(ui->listWidget->item(i)->text());
    vect = new QVector<K>(tree.getKeys(key));
    std::cout<<vect->size()<<"\n";
    if(vect->size()==0)
    {
        ui->info->setText(QString("Ключ не найден"));
        ui->info->setVisible(true);
    }
    else{
        ui->info->setText(QString("Ключ найден"));
        ui->info->setVisible(true);
    }
    if (vect->size()) {
        drawKey((*vect)[0]);
        position = 0;
    }
}

void MainWindow::on_addTreeElement_clicked()
{
    //Добавить пару ключ-значение
    K key;
    for (int i = 0; i < ui->listWidget->count(); i++)
        key.push_back(ui->listWidget->item(i)->text());
    V value = ui->letters->currentText();
    tree.addKVtoCollection(key, value);
    ui->deleteAll->setEnabled(true);
    ui->autoInsertKey->setEnabled(true);
    drawTree();
}

void MainWindow::on_deleteChosen_clicked()
{
    //Удаление выбранного ключа
    ui->info->setVisible(false);
    QTreeWidgetItem* item = ui->treeWidget->selectedItems()[0];
    QTreeWidgetItem* t = item;
    QTreeWidgetItem* end = ui->treeWidget->topLevelItem(0);
    K key;
    while (t != end) {
        key.push_front(t->text(0));
        t = t->parent();
    }
    tree.deleteKey(key);
    drawTree();
    if (!tree.getCountKeys())
        on_clearSequence_clicked();
    K key2;
    for (int i = 0; i < ui->listWidget->count(); i++)
        key2.push_back(ui->listWidget->item(i)->text());
    if (tree.checkHaveKey(key2)) {
        ui->letters->setCurrentText(tree[key2]);
    }
}

void MainWindow::on_deleteAll_clicked()
{
    //Удаление дерева
    ui->info->setVisible(false);
    tree.deleteAll();
    drawTree();
    ui->deleteAll->setEnabled(false);
    ui->autoInsertKey->setEnabled(false);
}

void MainWindow::on_downloadFromFile_clicked()
{

    QString filename = ui->fileName->text();
    if (!tree.Read(filename))
        QMessageBox::critical(this, "Ошибка","Коллекция не скачена");
    else
        QMessageBox::about(this, "Запись","Коллекция скачена успешно");
    drawTree();
}

void MainWindow::on_saveToFile_clicked()
{
    QString filename = ui->fileName->text();
    if (!tree.Write(filename))
        QMessageBox::critical(this, "Ошибка","Коллекция не записана");
    else
        QMessageBox::about(this, "Запись","Коллекция записана успешно");
    drawTree();
}
