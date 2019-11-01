#ifndef DBTABLEVIEW_H
#define DBTABLEVIEW_H

#include <QAbstractItemView>
#include <QTableView>
#include <QStandardItemModel>

class DBTableView : public QAbstractItemView
{
    Q_OBJECT

public:
    DBTableView();
    DBTableView(QWidget * parent = 0);

    QTableView *m_table;
    QStandardItemModel *m_model;

    int SetUpView(QWidget * parent = 0);
    int SetUpModel(int rows, int columns, QObject * parent = 0);
    int LoadDataBase();
    int SaveDataBase();

    virtual QRect visualRect(const QModelIndex&) const;
    virtual void scrollTo(const QModelIndex&, QAbstractItemView::ScrollHint);
    virtual QModelIndex indexAt(const QPoint&) const;
    virtual QModelIndex moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers);
    virtual int horizontalOffset() const;
    virtual int verticalOffset() const;
    virtual bool isIndexHidden(const QModelIndex&) const;
    virtual void setSelection(const QRect&, QItemSelectionModel::SelectionFlags);
    virtual QRegion visualRegionForSelection(const QItemSelection&) const;
};

#endif // DBTABLEVIEW_H
