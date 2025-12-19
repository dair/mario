#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "box.hpp"

class QBox : public QUIObject, public biv::Box
{
    Q_OBJECT
public:
	QBox(const biv::Coord& top_left, const int width, const int height, QWidget *parent = nullptr);

signals:

};
