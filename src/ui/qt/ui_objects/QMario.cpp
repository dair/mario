#include "QMario.h"

QMario::QMario(const biv::Coord& top_left, const int width, const int height, QWidget *parent)
    : QUIObject{parent},
      biv::Mario(top_left, width, height)
{

}
