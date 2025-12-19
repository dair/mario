#include "QBox.h"

QBox::QBox(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
	: QUIObject(Qt::GlobalColor::darkGreen, parent),
	  biv::Box(top_left, width, height)
{

}
