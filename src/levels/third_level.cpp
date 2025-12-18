#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_full_box({80, 17}, 5, 3);
	ui_factory->create_full_box({130, 5}, 5, 3);
	ui_factory->create_full_box({310, 2}, 5, 3);
	
	ui_factory->create_ship({30, 20}, 20, 7);
	ui_factory->create_ship({60, 25}, 30, 2);
	ui_factory->create_ship({100, 15}, 50, 2);
	ui_factory->create_ship({160, 20}, 40, 7);
	ui_factory->create_ship({210, 25}, 10, 2);
	ui_factory->create_ship({240, 20}, 50, 7);
	ui_factory->create_ship({270, 12}, 60, 2);
	ui_factory->create_ship({350, 20}, 20, 7);
	
	ui_factory->create_enemy({65, 5}, 3, 2);
	ui_factory->create_jump_enemy({105, 5}, 3, 2);
	ui_factory->create_jump_enemy({140, 5}, 3, 2);
	ui_factory->create_enemy({210, 5}, 3, 2);
	ui_factory->create_enemy({245, 5}, 3, 2);
	ui_factory->create_fly_enemy({260, 5}, 3, 2);
	ui_factory->create_fly_enemy({280, 5}, 3, 2);
}
