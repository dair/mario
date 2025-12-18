#include "console_jump_enemy.hpp"

using biv::ConsoleJumpEnemy;

ConsoleJumpEnemy::ConsoleJumpEnemy(const Coord& top_left, const int width, const int height) 
	: JumpEnemy(top_left, width, height) {}

char ConsoleJumpEnemy::get_brush() const noexcept {
	return 'j';
}
