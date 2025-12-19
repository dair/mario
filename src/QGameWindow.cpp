#include "QGameWindow.h"

#include <QDebug>
#include <QResizeEvent>

QGameWindow::QGameWindow(QWidget *parent)
    : QWidget{parent}
{

}

void QGameWindow::resizeEvent(QResizeEvent *event) {
	const QSize& newSize = event->size();

	qDebug() << __PRETTY_FUNCTION__ << "resize: " << newSize.width() << "x" << newSize.height();
}
