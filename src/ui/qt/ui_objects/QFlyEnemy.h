#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "fly_enemy.hpp"

class QFlyEnemy : public QUIObject, public biv::FlyEnemy
{
    Q_OBJECT
public:
	QFlyEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
