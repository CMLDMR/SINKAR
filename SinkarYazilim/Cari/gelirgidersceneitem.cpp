#include "gelirgidersceneitem.h"

GelirGiderSceneItem::GelirGiderSceneItem( qint64 _date , double _gelir , double _gider , double _max )
    :date(_date),gelir(_gelir),max(_max),gider(_gider)
{
}

QRectF GelirGiderSceneItem::boundingRect() const
{
    return QRectF(0,0,boundingRectWidth,40);
}

void GelirGiderSceneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->save();


    QString tarih = QDate::fromJulianDay(date).toString("dddd dd/MM/yyyy");
    auto tarihRect = option->fontMetrics.boundingRect( 0 , 10 , boundingRectWidth , 0 , Qt::AlignLeft , tarih );
    tarihRect.setX((-1)*tarihRect.width());
    painter->drawText(tarihRect,tarih);





    QRectF gelirRect( 0 , 0 , gelir/max*boundingRectWidth , 15 );
    painter->fillRect(gelirRect,QBrush(QColor(50,175,75)));

    QRectF gelirGrayRect( gelir/max*boundingRectWidth , 0 , boundingRectWidth - gelir/max*boundingRectWidth , 15 );
    painter->fillRect(gelirGrayRect,QBrush(QColor(225,225,225)));

    QString gelirText = QString("%1 TL").arg(gelir);
    auto gelirTextect = option->fontMetrics.boundingRect( 1 , 0 , boundingRectWidth , 0 , Qt::AlignLeft , gelirText );
    painter->setPen(Qt::white);
    painter->drawText(gelirTextect,gelirText);






    QRectF giderRect( 0 , gelirRect.bottom()+padding , gider/max*boundingRectWidth , 15 );
    painter->fillRect(giderRect,QBrush(QColor(175,50,75)));
    QRectF giderGrayRect( gider/max*boundingRectWidth , gelirRect.bottom()+padding  , boundingRectWidth - gider/max*boundingRectWidth , 15 );
    painter->fillRect(giderGrayRect,QBrush(QColor(225,225,225)));
    QString giderText = QString("%1 TL").arg(gider);
    auto giderTextect = option->fontMetrics.boundingRect( 1 , gelirRect.bottom()+padding , boundingRectWidth , 0 , Qt::AlignLeft , giderText );
    painter->setPen(Qt::white);
    painter->drawText(giderTextect,giderText);







    painter->restore();


}

void GelirGiderSceneItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void GelirGiderSceneItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
