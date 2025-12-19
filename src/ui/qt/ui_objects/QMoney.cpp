#include "QMoney.h"

QMoney::QMoney(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::yellow, parent),
	  biv::Money(top_left, width, height)
{

}
