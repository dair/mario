#pragma once

#include <QWidget>
#include "QUIObject.h"
#include "full_box.hpp"
#include "ui_factory.hpp"

class QFullBox : public QUIObject, public biv::FullBox
{
    Q_OBJECT
public:
	QFullBox(const biv::Coord& top_left, const int width, const int height, biv::UIFactory* ui_factory, QWidget *parent = nullptr);

signals:

};
