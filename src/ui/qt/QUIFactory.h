#pragma once

#include <memory>
#include <QObject>
#include "ui_factory.hpp"
#include "QGameMap.h"
#include "QMario.h"

class QUIFactory: public QObject, public biv::UIFactory {
    Q_OBJECT
private:
    std::unique_ptr<QGameMap> game_map;
    std::shared_ptr<QMario> mario;

public:
    QUIFactory(biv::Game *game);

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
