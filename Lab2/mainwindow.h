#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "prefixtree.h"
typedef QVector<QString> K;
typedef QString V;
typedef PrefixTree<QVector<QString>, QString> Tree;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertKey_clicked();

    void on_clearSequence_clicked();

    void on_autoInsertKey_clicked();

    void on_addTreeElement_clicked();

    void on_deleteChosen_clicked();

    void on_deleteAll_clicked();

    void on_downloadFromFile_clicked();

    void on_saveToFile_clicked();

private:
    Ui::MainWindow *ui;

    QStringList english = {"red", "orange", "yellow", "green", "blue", "black"};
    QStringList local;
    QVector<K>* vect = NULL;
    int position = 0;
    Tree tree;
    void drawTree();
    void drawKey(K& key);
};
#endif // MAINWINDOW_H
