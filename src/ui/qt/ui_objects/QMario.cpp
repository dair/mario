#include "QMario.h"

QMario::QMario(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::red, parent),
      biv::Mario(top_left, width, height)
{

}
