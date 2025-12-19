#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "ship.hpp"

class QShip: public QUIObject, public biv::Ship
{
    Q_OBJECT
public:
	QShip(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
