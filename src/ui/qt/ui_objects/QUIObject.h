#pragma once

#include <QWidget>
#include "rect.hpp"

class QUIObject : public QWidget, virtual public biv::Rect
{
    Q_OBJECT
public:
	explicit QUIObject(QColor color, QWidget *parent = nullptr);

signals:

};
