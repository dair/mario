#ifndef QMARIO_H
#define QMARIO_H

#include <QWidget>
#include "QUIObject.h"
#include "mario.hpp"

class QMario : public QUIObject, public biv::Mario
{
    Q_OBJECT
public:
    QMario(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};

#endif // QMARIO_H
