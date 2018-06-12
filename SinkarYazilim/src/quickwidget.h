#ifndef QUICKWIDGET_H
#define QUICKWIDGET_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog() {


        mMainLayout = new QVBoxLayout();

        ContentLayout = new QVBoxLayout();

        CloseLayout = new QHBoxLayout();

        closeBtn = new QPushButton("Kapat");

        connect(closeBtn,&QPushButton::clicked,this,&Dialog::close);

        setLayout(mMainLayout);
        mMainLayout->addLayout(ContentLayout);
        mMainLayout->addLayout(CloseLayout);
        CloseLayout->addWidget(closeBtn);

        setWindowFlag(Qt::FramelessWindowHint);
        setStyleSheet("QDialog{border:1px solid black;}");

    }
    virtual ~Dialog() {}

    template<typename T>
    T* addLayout(){
        T* _layout = new T();
        ContentLayout->addLayout(_layout);
        return _layout;
    }





private:

    QVBoxLayout* mMainLayout;
    QVBoxLayout* ContentLayout;
    QHBoxLayout* CloseLayout;

    QPushButton* closeBtn;

};




class HLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    HLayout() {}
    virtual ~HLayout() {}

    template<typename T>
    T* addLayout(){
        T* _layout = new T();
        addLayout(_layout);
        return _layout;
    }

    template<typename T,typename arg>
    T* addwidget(arg _arg){
        T* widget = new T(_arg);
        addWidget(widget);
        return widget;
    }

    template<typename T>
    T* addwidget(){
        T* widget = new T();
        addWidget(widget);
        return widget;
    }
};

class VLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    VLayout() {}
    virtual ~VLayout() {}

    template<typename T>
    T* addlayout(){
        T* _layout = new T();
        addLayout(_layout);
        return _layout;
    }

    template<typename T,typename arg>
    T* addwidget(arg _arg){
        T* widget = new T(_arg);
        addWidget(widget);
        return widget;
    }

    template<typename T>
    T* addwidget(){
        T* widget = new T();
        addWidget(widget);
        return widget;
    }
};






#endif // QUICKWIDGET_H
