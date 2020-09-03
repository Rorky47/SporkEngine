#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPORK_API _declspec(dllexport)
	#else
		#define SPORK_API _declspec(dllimport)
	#endif
#else 
	#error only windows for now
#endif // SP_PLATFORM_WINDOWS
