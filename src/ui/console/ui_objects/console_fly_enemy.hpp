#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "fly_enemy.hpp"

namespace biv {
	class ConsoleFlyEnemy : public FlyEnemy, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleFlyEnemy(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
