#include "QUIFactory.h"

#include <QGridLayout>

#include "QMario.h"
#include "QBox.h"
#include "QEnemy.h"
#include "QJumpEnemy.h"
#include "QFlyEnemy.h"
#include "QFullBox.h"
#include "QMoney.h"
#include "QShip.h"

QUIFactory::QUIFactory(biv::Game *game, QWidget* parent):
    biv::UIFactory(game),
	game_map(std::make_unique<QGameMap>(200, 30, parent))
{
	auto layout = new QGridLayout(parent);
	layout->addWidget(game_map.get(), 0, 0);
	layout->setColumnStretch(0, 1);
	layout->setRowStretch(0, 1);
	game_map->show();
}

void QUIFactory::clear_data() {
    game->remove_objs();
    game_map->remove_objs();
    mario = nullptr;

	boxes.clear();
	full_boxes.clear();
	ships.clear();
	enemies.clear();
	jump_enemies.clear();
	fly_enemies.clear();
	moneys.clear();
}

void QUIFactory::create_box(
        const biv::Coord& top_left, const int width, const int height) {
	auto box = std::make_shared<QBox>(top_left, width, height, game_map.get());
	boxes.push_back(box);

	game->add_map_movable(box.get());
	game->add_static_obj(box.get());
	game_map->add_obj(box);
}

void QUIFactory::create_enemy(
        const biv::Coord& top_left, const int width, const int height) {
	auto enemy = std::make_shared<QEnemy>(top_left, width, height, game_map.get());

	enemies.push_back(enemy);
	game->add_map_movable(enemy.get());
	game->add_movable(enemy.get());
	game->add_collisionable(enemy.get());
	game_map->add_obj(enemy);
}

void QUIFactory::create_jump_enemy(
        const biv::Coord& top_left, const int width, const int height) {
	auto jump_enemy = std::make_shared<QJumpEnemy>(top_left, width, height);
	jump_enemies.push_back(jump_enemy);
	game->add_map_movable(jump_enemy.get());
	game->add_movable(jump_enemy.get());
	game->add_collisionable(jump_enemy.get());
	game_map->add_obj(jump_enemy);
}

void QUIFactory::create_fly_enemy(
        const biv::Coord& top_left, const int width, const int height) {
	auto fly_enemy = std::make_shared<QFlyEnemy>(top_left, width, height);
	fly_enemies.push_back(fly_enemy);
	game->add_map_movable(fly_enemy.get());
	game->add_movable(fly_enemy.get());
	game->add_collisionable(fly_enemy.get());
	game->add_updatable(fly_enemy.get());
	game_map->add_obj(fly_enemy);
}

void QUIFactory::create_full_box(
        const biv::Coord& top_left, const int width, const int height) {
	auto full_box = std::make_shared<QFullBox>(top_left, width, height, this);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box.get());
	game->add_map_movable(full_box.get());
	game->add_static_obj(full_box.get());
	game_map->add_obj(full_box);
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
	auto money = std::make_shared<QMoney>(top_left, width, height);
	moneys.push_back(money);
	game->add_map_movable(money.get());
	game->add_movable(money.get());
	game->add_collisionable(money.get());
	game_map->add_obj(money);
}

void QUIFactory::create_ship(
        const biv::Coord& top_left, const int width, const int height) {
	auto ship = std::make_shared<QShip>(top_left, width, height);
	ships.push_back(ship);
	game->add_map_movable(ship.get());
	game->add_static_obj(ship.get());
	game_map->add_obj(ship);
}

biv::GameMap* QUIFactory::get_game_map() {
    return game_map.get();
}

biv::Mario* QUIFactory::get_mario() {
    return mario.get();
}
