#include "QFullBox.h"

QFullBox::QFullBox(const biv::Coord& top_left, const int width, const int height, biv::UIFactory* ui_factory, QWidget *parent)
	: QUIObject(Qt::GlobalColor::green, parent),
	  biv::FullBox(top_left, width, height, ui_factory)
{

}
