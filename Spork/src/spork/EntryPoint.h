#pragma once


#ifdef SP_PLATFORM_WINDOWS

extern spork::Engine* spork::StartEngine();

int main(int argc, char** argv)
{
	spork::Log::Init();
	SP_CORE_INFO("Entry Point!");

	auto app = spork::StartEngine();
	app->Run();
	delete app;
}

#endif