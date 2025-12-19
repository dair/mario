#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "money.hpp"

class QMoney: public QUIObject, public biv::Money
{
    Q_OBJECT
public:
	QMoney(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
