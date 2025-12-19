#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "jump_enemy.hpp"

class QJumpEnemy : public QUIObject, public biv::JumpEnemy
{
    Q_OBJECT
public:
	QJumpEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
