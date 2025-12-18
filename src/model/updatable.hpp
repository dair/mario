#pragma once

#include "rect.hpp"
#include "speed.hpp"

namespace biv {
	class Updatable {
		public:
			virtual void update() noexcept = 0;
	};
}