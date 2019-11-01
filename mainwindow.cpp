#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeView>
#include <QTableWidget>
#include <QTabWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化m_vecDB0,m_vecDB1
    m_vecDB0.push_back(m_DB0);
    m_vecDB0.push_back(m_DB1);
    m_vecDB0.push_back(m_DB2);
    m_vecDB0.push_back(m_DB3);
    m_vecDB0.push_back(m_DB4);
    m_vecDB1.push_back(m_DB5);
    m_vecDB1.push_back(m_DB6);
    m_vecDB1.push_back(m_DB7);
    m_vecDB1.push_back(m_DB8);
    m_vecDB1.push_back(m_DB9);


    //添加tabWidget
    ui->tabWidget->showMaximized();
    ui->tabWidget->show();

    QWidget *dockChildWidget = new QWidget(this);

    //创建树形视图
    QTreeView *tree = new QTreeView(ui->dockWidget);

    //创建模型
    QStandardItemModel *model = new QStandardItemModel(tree);
    model->setHorizontalHeaderLabels(QStringList()<<QString(tr("项目名")));

    //为视图指定模型
    tree->setModel(model);

    QStandardItem* itemProject0 = new QStandardItem(QString(tr("项目表1")));
    itemProject0->setEditable(false);
    model->appendRow(itemProject0);

    //添加项目数据表子项
    QStandardItem* itemChild0 = new QStandardItem(QString(tr("数据表0")));
    itemProject0->appendRow(itemChild0);
    QStandardItem* itemChild1 = new QStandardItem(QString(tr("数据表1")));
    itemProject0->appendRow(itemChild1);
    QStandardItem* itemChild2 = new QStandardItem(QString(tr("数据表2")));
    itemProject0->appendRow(itemChild2);
    QStandardItem* itemChild3 = new QStandardItem(QString(tr("数据表3")));
    itemProject0->appendRow(itemChild3);
    QStandardItem* itemChild4 = new QStandardItem(QString(tr("数据表4")));
    itemProject0->appendRow(itemChild4);

    //设置子项表不可编辑
    itemChild0->setEditable(false);
    itemChild1->setEditable(false);
    itemChild2->setEditable(false);
    itemChild3->setEditable(false);
    itemChild4->setEditable(false);

    QStandardItem* itemProject1 = new QStandardItem(QString(tr("项目表2")));
    itemProject1->setEditable(false);
    model->appendRow(itemProject1);

    QStandardItem* itemChild5 = new QStandardItem(QString(tr("数据表5")));
    itemProject1->appendRow(itemChild5);
    QStandardItem* itemChild6 = new QStandardItem(QString(tr("数据表6")));
    itemProject1->appendRow(itemChild6);
    QStandardItem* itemChild7 = new QStandardItem(QString(tr("数据表7")));
    itemProject1->appendRow(itemChild7);
    QStandardItem* itemChild8 = new QStandardItem(QString(tr("数据表8")));
    itemProject1->appendRow(itemChild8);
    QStandardItem* itemChild9 = new QStandardItem(QString(tr("数据表9")));
    itemProject1->appendRow(itemChild9);

    //设置子项表不可编辑
    itemChild5->setEditable(false);
    itemChild6->setEditable(false);
    itemChild7->setEditable(false);
    itemChild8->setEditable(false);
    itemChild9->setEditable(false);

    QVBoxLayout *VerticalLayout = new QVBoxLayout(dockChildWidget);
    VerticalLayout->addWidget(tree);
    dockChildWidget->setLayout(VerticalLayout);
    ui->dockWidget->setWidget(dockChildWidget);
    tree->show();
    tree->expandAll();
    
    connect(tree, SIGNAL(doubleClicked ( const QModelIndex)), this,  SLOT(TreeView_DoubleClick(const QModelIndex)));
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this, SLOT(RemoveSubTab(int)));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(CurrentTabIndexChange(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TreeView_DoubleClick(const QModelIndex &index)
{
//    QString str;
//    str += QString(tr("当前选中：%1\nrow:%2, column:%3\n")).arg(index.data().toString())
//                           .arg(index.row()).arg(index.column());
//    str += QString(tr("父级：%1\n")).arg(index.parent().data().toString());
//    qDebug() << "Text: " << str << endl;

    int index_parent_row = index.parent().row();
    QString strData = index.data().toString();
    if((strData.compare(QString(tr("项目表1"))) != 0) &&
            (strData.compare(QString(tr("项目表2"))) != 0)) {
        switch(index_parent_row) {
        case 0:
            OpenvecDB0View(index);
            break;
        case 1:
            OpenvecDB1View(index);
            break;
        default:
            break;
        }
    }
}

void MainWindow::RemoveSubTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::OpenvecDB0View(const QModelIndex &index)
{
    int index_row = index.row();
    int tabCnt = ui->tabWidget->count();
    int DBflag = 0;
    for(int i = 0; i < tabCnt; ++i) {
        QString DBText = index.data().toString();
        QString cmpText = ui->tabWidget->tabText(i);
        if(DBText.compare(cmpText) == 0) {
            DBflag = 1;
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }
    if (DBflag != 1) {
        m_vecDB0[index_row] = new DBTableView(ui->tabWidget);
        ui->tabWidget->addTab(m_vecDB0[index_row]->m_table, index.data().toString());
        ui->tabWidget->setTabsClosable(true);
        ui->tabWidget->setCurrentWidget(m_vecDB0[index_row]->m_table);
    }
}

void MainWindow::OpenvecDB1View(const QModelIndex &index)
{
    int index_row = index.row();
    int tabCnt = ui->tabWidget->count();
    int DBflag = 0;
    for(int i = 0; i < tabCnt; ++i) {
        QString DBText = index.data().toString();
        QString cmpText = ui->tabWidget->tabText(i);
        if(DBText.compare(cmpText) == 0) {
            DBflag = 1;
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }
    if (DBflag != 1) {
        m_vecDB1[index_row] = new DBTableView(ui->tabWidget);
        ui->tabWidget->addTab(m_vecDB1[index_row]->m_table, index.data().toString());
        ui->tabWidget->setTabsClosable(true);
        ui->tabWidget->setCurrentWidget(m_vecDB1[index_row]->m_table);
    }
}

void MainWindow::CurrentTabIndexChange(int index)
{
    //qDebug() << "Current Index: " << index << endl;
}

void MainWindow::on_actionAdd_triggered()
{
    int CurrentIndex = ui->tabWidget->currentIndex();
    QString TabName = ui->tabWidget->tabText(CurrentIndex);
    int DBindex = 0;
    QStandardItem NewItem;
    QRegExp rx("(\\d+)");  // 匹配数字
    int pos = 0;
    while ((pos = rx.indexIn(TabName, pos)) != -1) {
        DBindex = rx.cap(0).toInt();
        pos += rx.matchedLength();
    }
    if(DBindex > 4) {
        m_vecDB1[DBindex - 5]->m_model->appendRow(&NewItem);
        m_vecDB1[DBindex - 5]->m_table->setModel(m_vecDB1[DBindex - 5]->m_model);
    }
    else if(DBindex <= 4) {
        m_vecDB0[DBindex]->m_model->appendRow(&NewItem);
        m_vecDB0[DBindex]->m_table->setModel(m_vecDB0[DBindex]->m_model);
    }
}
