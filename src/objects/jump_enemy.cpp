#include "jump_enemy.hpp"

#include "map_movable.hpp"

using biv::JumpEnemy;

JumpEnemy::JumpEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0.2;
	hspeed = 0;
	is_fly = false;
}

biv::Rect JumpEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed JumpEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

//предпочту не менять названия, а то всё ломается:')
void JumpEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	move_vertically();
}

void JumpEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void JumpEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = -vspeed;
	}
}
