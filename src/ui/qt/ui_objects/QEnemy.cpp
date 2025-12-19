#include "QEnemy.h"

QEnemy::QEnemy(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::magenta, parent),
	  biv::Enemy(top_left, width, height)
{

}
