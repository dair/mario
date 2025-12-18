#ifndef QUIOBJECT_H
#define QUIOBJECT_H

#include <QWidget>

class QUIObject : public QWidget
{
    Q_OBJECT
public:
    explicit QUIObject(QWidget *parent = nullptr);

signals:

};

#endif // QUIOBJECT_H
