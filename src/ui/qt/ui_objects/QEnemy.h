#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "enemy.hpp"

class QEnemy : public QUIObject, public biv::Enemy
{
    Q_OBJECT
public:
	QEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
