#pragma once

#include <memory>
#include <QObject>
#include <QWidget>
#include <vector>
#include "ui_factory.hpp"
#include "QGameMap.h"

class QMario;
class QBox;
class QFullBox;
class QShip;
class QJumpEnemy;
class QFlyEnemy;
class QEnemy;
class QMoney;

class QUIFactory: public QObject, public biv::UIFactory {
	Q_OBJECT
private:
	std::unique_ptr<QGameMap> game_map;
	std::shared_ptr<QMario> mario;
	std::vector<std::shared_ptr<QBox>> boxes;
	std::vector<std::shared_ptr<QFullBox>> full_boxes;
	std::vector<std::shared_ptr<QShip>> ships;
	std::vector<std::shared_ptr<QJumpEnemy>> jump_enemies;
	std::vector<std::shared_ptr<QFlyEnemy>> fly_enemies;
	std::vector<std::shared_ptr<QEnemy>> enemies;
	std::vector<std::shared_ptr<QMoney>> moneys;

public:
	QUIFactory(biv::Game *game, QWidget* parent);

	virtual void clear_data();
	virtual void create_box(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_enemy(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_jump_enemy(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_fly_enemy(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_full_box(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_mario(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_money(
		const biv::Coord& top_left, const int width, const int height);
	virtual void create_ship(
		const biv::Coord& top_left, const int width, const int height);
	virtual biv::GameMap* get_game_map();
	virtual biv::Mario* get_mario();
};
