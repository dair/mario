#include "QGame.h"
#include "QUIFactory.h"
#include <QDebug>
#include <memory>
#include "QGameMap.h"

QGame::QGame(QWidget* widgetParent, QObject *parent)
    : QObject{parent},
      game() {
    biv::os::init_settings();

	ui_factory = new QUIFactory(&game, widgetParent);
    game_map = ui_factory->get_game_map();
    game_level = new biv::FirstLevel(ui_factory);
    mario = ui_factory->get_mario();

	auto qGameMap = dynamic_cast<QGameMap*>(game_map);
	if (qGameMap != nullptr) {
		QObject::connect(qGameMap, &QGameMap::userInput, this, &QGame::onKeyEvent);
	}
}

QGame::~QGame() {
    delete game_level;
    delete ui_factory;
}

void QGame::onTimer() {
	// 2. Обработка пользовательского ввода
	processKeyEvent();
    // 3. Обновление внутреннего состояния игры
    game.update();
    game.move_objs_horizontally();
    game.check_horizontally_static_collisions();

    game.move_objs_vertically();
    game.check_mario_collision();
    game.check_vertically_static_collisions();

    if (
        game_map->is_below_map(mario->get_top())
        || !mario->is_active()
    ) {
        game_level->restart();
        mario = ui_factory->get_mario();
//            std::this_thread::sleep_for(1000ms);
    }

    if (game.is_level_end()) {
        if (!game_level->is_final()) {
            game_level = game_level->get_next();
            mario = ui_factory->get_mario();
//                std::this_thread::sleep_for(1000ms);
            game.start_level();
        } else {
            game.finish();
        }
    }

    // 4. Обновление изображения на экране
    game_map->refresh();
    biv::os::set_cursor_start_position();
    game_map->show();

    // 6. Завершение
    if (game.is_finished()) {
        emit gameOver();
    }
}

void QGame::processKeyEvent() {
	if ((keyEvents & (int)biv::os::UserInput::MAP_LEFT) == (int)biv::os::UserInput::MAP_LEFT) {
		mario->move_map_left();
		if (!game.check_static_collisions(mario)) {
			game.move_map_left();
		}
		mario->move_map_right();
	}

	if ((keyEvents & (int)biv::os::UserInput::MAP_RIGHT) == (int)biv::os::UserInput::MAP_RIGHT) {
		mario->move_map_right();
		if (!game.check_static_collisions(mario)) {
			game.move_map_right();
		}
		mario->move_map_left();
	}

	if ((keyEvents & (int)biv::os::UserInput::MARIO_JUMP) == (int)biv::os::UserInput::MARIO_JUMP) {
		mario->jump();
	}
}

void QGame::onKeyEvent(int input) {
	if (input == (int)biv::os::UserInput::EXIT) {
		game.finish();
		return;
	}

	keyEvents = input;
}

