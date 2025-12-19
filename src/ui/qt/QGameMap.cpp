#include "QGameMap.h"
#include <QGridLayout>
#include <QResizeEvent>
#include <QDebug>

QGameMap::QGameMap(const int height, const int width, QWidget* parent):
	QWidget(parent),
    biv::GameMap(width, height)
{
	QPalette pal = palette();
	pal.setColor(QPalette::Window, Qt::black); // QPalette::Window is the general background role
	setAutoFillBackground(true); // Required for palette background to show
	setPalette(pal);

	grabKeyboard();
}

void QGameMap::resizeEvent(QResizeEvent *event) {
	const QSize& newSize = event->size();

	qDebug() << __PRETTY_FUNCTION__ << "resize: " << newSize.width() << "x" << newSize.height();

	// cell size
	int gameWidth = GameMap::width;
	int gameHeight = GameMap::height;

	int cellWidth = newSize.width() / gameWidth;
	int cellHeight = newSize.height() / gameHeight;
	int size = std::min(cellWidth, cellHeight);
	cellSize = QSize(size, size);
	qDebug() << __PRETTY_FUNCTION__ << "game size: " << gameWidth << "x" << gameHeight;
	qDebug() << __PRETTY_FUNCTION__ << "cell size: " << cellSize.width() << "x" << cellSize.height();

	refresh();
}

void QGameMap::clear() noexcept {

}

void QGameMap::refresh() noexcept {
	for (auto object : objects) {
		positionObject(object);
	}
}

void QGameMap::remove_objs() {
	objects.clear();
}

void QGameMap::show() const noexcept {

}

void QGameMap::remove_obj(std::shared_ptr<QUIObject> object) {
	objects.erase(object);
	object->hide();
}

void QGameMap::add_obj(std::shared_ptr<QUIObject> object) {
	objects.insert(object);
	object->setParent(this);
	positionObject(object);
	object->show();
}

void QGameMap::positionObject(std::shared_ptr<QUIObject> object) {
	object->move(object->get_left() * cellSize.width(), object->get_top() * cellSize.height());
	object->setFixedSize(cellSize.width() * object->get_width(), cellSize.height() * object->get_height());
}

void QGameMap::keyPressEvent(QKeyEvent *event) {
	qDebug() << event->key();
	biv::os::UserInput input;
	switch (event->key()) {
		case Qt::Key_Up:
			input = biv::os::UserInput::MARIO_JUMP;
			break;
		case Qt::Key_Left:
			input = biv::os::UserInput::MAP_RIGHT;
			break;
		case Qt::Key_Right:
			input = biv::os::UserInput::MAP_LEFT;
			break;
		case Qt::Key_Escape:
			input = biv::os::UserInput::EXIT;
			break;
	default:
		return;
	}

	emit userInput(input);
}
