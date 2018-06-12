#ifndef GELIRGIDERSCENEITEM_H
#define GELIRGIDERSCENEITEM_H

#include <QtCore/qglobal.h>

#include <QPainter>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QDate>

#include <QDebug>

#define con qDebug()



class GelirGiderSceneItem : public QGraphicsItem
{
public:
    GelirGiderSceneItem(qint64 _date, double _gelir , double _gider , double _max = 100 );

    QRectF boundingRect() const;

    void paint(QPainter* painter , const QStyleOptionGraphicsItem* option , QWidget* widget);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    double gelir;
    double gider;
    double max;
    qint64 date;

    const qreal boundingRectWidth = 100.0;

    const int padding = 2;
};

#endif // GELIRGIDERSCENEITEM_H
