#pragma once

#include "Core.h"

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
