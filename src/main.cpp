/**
	Игровой цикл - это обощённое представление потока событий, происходящих в игре.

	Игровой цикл:
		1. Установка параметров игры
		2. Получение пользовательского ввода
		3. Обновление внутреннего состояния игры
		4. Обновление изображения на экране
		5. Проверка того, не окончена ли игра

		*** Если игра не окончена, то возвращаемся в пункт № 2.

		6. Завершение
*/
#include <thread>
#include <QApplication>
#include <QTimer>
#include <QObject>
#include "QGame.h"
#include "QGameWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QGameWindow window;
	window.setBaseSize(2000, 200);
	QGame qGame(&window, &app);
	QTimer* timer = new QTimer(&app);
	timer->setInterval(10);
	QObject::connect(timer, &QTimer::timeout, &qGame, &QGame::onTimer);
	QObject::connect(&qGame, &QGame::gameOver, &app, &QApplication::quit);
	timer->start();

    window.show();

    int ret = app.exec();

    timer->stop();
    delete timer;
    return ret;
}
