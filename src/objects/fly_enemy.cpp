#include "fly_enemy.hpp"

#include "map_movable.hpp"

using biv::FlyEnemy;

FlyEnemy::FlyEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height), c(0) {
	vspeed = 0;
	hspeed = 0.2;
	is_fly = true;
}

biv::Rect FlyEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

bool FlyEnemy::get_fly() const noexcept {
	return is_fly;
}

void FlyEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		is_fly = false;
		kill();
	} else {
		mario->kill();
	}
}

void FlyEnemy::process_vertical_static_collision(Rect* obj) noexcept {}

void FlyEnemy::update() noexcept {
	++c;
	if (c >= 300) {
		process_horizontal_static_collision(nullptr);
		c = 0;
	}
}

