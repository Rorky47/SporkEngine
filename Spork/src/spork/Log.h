#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace spork{

	class SPORK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core logging macros
#define SP_CORE_TRACE(...) ::spork::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_WARN(...)  ::spork::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::spork::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_INFO(...)  ::spork::Log::GetCoreLogger()->info(__VA_ARGS__)

//Client logging macros
#define SP_CLIENT_TRACE(...) ::spork::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_CLIENT_WARN(...)  ::spork::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_CLIENT_ERROR(...) ::spork::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_CLIENT_INFO(...)  ::spork::Log::GetClientLogger()->info(__VA_ARGS__)



