#pragma once

#include "Macros.h"

namespace spork {

	class SPORK_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();
	};

	Engine* StartEngine();

}
