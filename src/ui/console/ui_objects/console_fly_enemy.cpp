#include "console_fly_enemy.hpp"

using biv::ConsoleFlyEnemy;

ConsoleFlyEnemy::ConsoleFlyEnemy(const Coord& top_left, const int width, const int height) 
	: FlyEnemy(top_left, width, height) {}

char ConsoleFlyEnemy::get_brush() const noexcept {
	return 'f';
}
