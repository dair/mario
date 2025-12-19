#include "QFlyEnemy.h"

QFlyEnemy::QFlyEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::white, parent),
	  biv::FlyEnemy(top_left, width, height)
{

}
