#include "QUIFactory.h"

QUIFactory::QUIFactory(biv::Game *game):
    biv::UIFactory(game),
    game_map(std::make_unique<QGameMap>(30, 200, this))
{
}

void QUIFactory::clear_data() {
    game->remove_objs();
    game_map->remove_objs();
    mario = nullptr;

//    boxes.clear();
//    full_boxes.clear();
//    ships.clear();
//    enemies.clear();
//    jump_enemies.clear();
//    fly_enemies.clear();
//    moneys.clear();
}

void QUIFactory::create_box(
        const biv::Coord& top_left, const int width, const int height) {
}

void QUIFactory::create_enemy(
        const biv::Coord& top_left, const int width, const int height) {

}

void QUIFactory::create_jump_enemy(
        const biv::Coord& top_left, const int width, const int height) {

}

void QUIFactory::create_fly_enemy(
        const biv::Coord& top_left, const int width, const int height) {

}

void QUIFactory::create_full_box(
        const biv::Coord& top_left, const int width, const int height) {

}

void QUIFactory::create_mario(
        const biv::Coord& top_left, const int width, const int height) {
    if (mario != nullptr) {
        game->remove_collisionable(mario.get());
        game->remove_movable(mario.get());
        game->remove_mario();
        game_map->remove_obj(mario);
        mario = nullptr;
    }

    mario = std::make_unique<QMario>(top_left, width, height);
    game->add_collisionable(mario.get());
    game->add_movable(mario.get());
    game->add_mario(mario.get());
    game_map->add_obj(mario);
}

void QUIFactory::create_money(
        const biv::Coord& top_left, const int width, const int height) {

}

void QUIFactory::create_ship(
        const biv::Coord& top_left, const int width, const int height) {


}

biv::GameMap* QUIFactory::get_game_map() {
    return game_map.get();
}

biv::Mario* QUIFactory::get_mario() {
    return mario.get();
}
