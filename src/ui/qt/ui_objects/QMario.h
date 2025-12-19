#pragma once

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
