#include "QJumpEnemy.h"

QJumpEnemy::QJumpEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::white, parent),
	  biv::JumpEnemy(top_left, width, height)
{

}
