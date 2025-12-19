#pragma once

namespace biv {
	namespace os {
		enum class UserInput {
			EXIT = -1,
			NO_INPUT = 0,
			MAP_LEFT = 1,
			MAP_RIGHT = 2,
			MARIO_JUMP = 4
		};
	
		UserInput get_user_input();
	}
}
