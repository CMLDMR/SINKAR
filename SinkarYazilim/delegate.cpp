#include "delegate.h"



void Delegate::KisiDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString isim = index.data(Qt::DisplayRole).toString();

    QFont font = QApplication::font();

    QFontMetrics fontMetrics(font);

    QRect textRect = fontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,isim);



    painter->save();

    if( option.state & QStyle::StateFlag::State_Selected )
    {
        painter->fillRect(option.rect,option.palette.highlight());
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }

    painter->setFont(font);

    painter->drawText(textRect,isim);

    painter->restore();
}

QSize Delegate::KisiDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString isim = index.data(Qt::DisplayRole).toString();

    QFont font = QApplication::font();

    QFontMetrics fontMetrics(font);

    QRect textRect = fontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,isim);

    return QSize(option.rect.width(),textRect.height() + 2 * padding);
}
