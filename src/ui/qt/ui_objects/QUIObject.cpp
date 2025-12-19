#include "QUIObject.h"

QUIObject::QUIObject(QColor color, QWidget *parent)
    : QWidget{parent}
{
	QPalette pal = palette();
	pal.setColor(QPalette::Window, color); // QPalette::Window is the general background role
	setAutoFillBackground(true); // Required for palette background to show
	setPalette(pal);
}
