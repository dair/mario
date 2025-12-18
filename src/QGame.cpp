#include "QGame.h"
#include "QUIFactory.h"
#include <QDebug>

QGame::QGame(QObject *parent)
    : QObject{parent},
      game() {
    biv::os::init_settings();

    ui_factory = new QUIFactory(&game);
    game_map = ui_factory->get_game_map();
    game_level = new biv::FirstLevel(ui_factory);
    mario = ui_factory->get_mario();
}

QGame::~QGame() {
    delete game_level;
    delete ui_factory;
}

void QGame::onTimer() {
    qDebug() << "onTimer";
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
