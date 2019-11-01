#include "dbtableview.h"

DBTableView::DBTableView()
{
    SetUpModel(0, 0, this);
    SetUpView();
}

DBTableView::DBTableView(QWidget *parent)
{
    SetUpModel(0, 0, this);

    //新建一个QTableView对象
    m_table = new QTableView(parent);

    //为QTableView对象设置相同的Model
    m_table->setModel (m_model);
}

int DBTableView::SetUpView(QWidget * parent)
{
    //新建一个QTableView对象
    m_table = new QTableView(parent);

    //为QTableView对象设置相同的Model
    m_table->setModel (m_model);
    return 0;
}

int DBTableView::SetUpModel(int rows, int columns, QObject * parent)
{
    m_model = new QStandardItemModel(rows, columns, parent);
    return 0;
}

int DBTableView::LoadDataBase()
{
    return 0;
}

int DBTableView::SaveDataBase()
{
    return 0;
}

QRect DBTableView::visualRect(const QModelIndex &) const
{
    QRect nullQRect;
    return nullQRect;
}

void DBTableView::scrollTo(const QModelIndex &, QAbstractItemView::ScrollHint)
{

}

QModelIndex DBTableView::indexAt(const QPoint &) const
{
    QModelIndex nullIndex;
    return nullIndex;
}

QModelIndex DBTableView::moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers)
{
    QModelIndex nullIndex;
    return nullIndex;
}

int DBTableView::horizontalOffset() const
{
    return 0;
}

int DBTableView::verticalOffset() const
{
    return 0;
}

bool DBTableView::isIndexHidden(const QModelIndex &) const
{
    return 0;
}

void DBTableView::setSelection(const QRect &, QItemSelectionModel::SelectionFlags)
{

}

QRegion DBTableView::visualRegionForSelection(const QItemSelection &) const
{
    QRegion nullRegion;
    return nullRegion;
}


