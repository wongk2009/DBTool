#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QModelIndex>
#include <QTableView>
#include <QVector>
#include <QDateTime>
#include "dbtableview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //保存的数据表
    DBTableView *m_DB0;
    DBTableView *m_DB1;
    DBTableView *m_DB2;
    DBTableView *m_DB3;
    DBTableView *m_DB4;
    DBTableView *m_DB5;
    DBTableView *m_DB6;
    DBTableView *m_DB7;
    DBTableView *m_DB8;
    DBTableView *m_DB9;

    //数据表访问向量
    QVector<DBTableView *> m_vecDB0;
    QVector<DBTableView *> m_vecDB1;

    //数据表最后修改时间
    QDateTime m_DB0LastSaveTime;
    QDateTime m_DB1LastSaveTime;
    QDateTime m_DB2LastSaveTime;
    QDateTime m_DB3LastSaveTime;
    QDateTime m_DB4LastSaveTime;
    QDateTime m_DB5LastSaveTime;
    QDateTime m_DB6LastSaveTime;
    QDateTime m_DB7LastSaveTime;
    QDateTime m_DB8LastSaveTime;
    QDateTime m_DB9LastSaveTime;

private slots:
    void TreeView_DoubleClick(const QModelIndex & index);
    void RemoveSubTab(int index);
    void OpenvecDB0View(const QModelIndex &index);
    void OpenvecDB1View(const QModelIndex &index);
    void CurrentTabIndexChange(int index);

    void on_actionAdd_triggered();

};

#endif // MAINWINDOW_H
