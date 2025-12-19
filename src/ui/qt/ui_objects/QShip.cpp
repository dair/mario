#include "QShip.h"

QShip::QShip(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::lightGray, parent),
	  biv::Ship(top_left, width, height)
{

}
