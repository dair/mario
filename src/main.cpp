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
    QGame qGame;
    QTimer* timer = new QTimer(&app);
    timer->setInterval(10);
    QObject::connect(timer, &QTimer::timeout, &qGame, &QGame::onTimer);
    QObject::connect(&qGame, &QGame::gameOver, &app, &QApplication::quit);
    timer->start();

    QGameWindow window;
    window.show();

    int ret = app.exec();

    timer->stop();
    delete timer;
    return ret;
}

//int game_main() {
//	// 1. Установка параметров игры
//	using namespace std::chrono_literals;
	
//	biv::os::UserInput user_input;
//	do {
//		// 2. Получение пользовательского ввода
//		user_input = biv::os::get_user_input();
//		switch (user_input) {
//			case biv::os::UserInput::MAP_LEFT:
//				mario->move_map_left();
//				if (!game.check_static_collisions(mario)) {
//					game.move_map_left();
//				}
//				mario->move_map_right();
//				break;
//			case biv::os::UserInput::MAP_RIGHT:
//				mario->move_map_right();
//				if (!game.check_static_collisions(mario)) {
//					game.move_map_right();
//				}
//				mario->move_map_left();
//				break;
//			case biv::os::UserInput::MARIO_JUMP:
//				mario->jump();
//				break;
//			case biv::os::UserInput::EXIT:
//				game.finish();
//				break;
//		}
		
	
//}
