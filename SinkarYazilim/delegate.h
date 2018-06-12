#ifndef DELEGATE_H
#define DELEGATE_H

#include <QtCore/qglobal.h>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QApplication>


namespace Delegate {
class KisiDelegate : public QStyledItemDelegate
{
public:
    KisiDelegate() {}

    void paint(QPainter* painter,const QStyleOptionViewItem &option , const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const;

    enum Role
    {
        Oid = Qt::UserRole + 1
    };

private:
    const int padding = 5;

};
}




#endif // DELEGATE_H
