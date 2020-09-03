#include <Spork.h>

class Sandbox : public spork::Engine
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}
};

spork::Engine* spork::StartEngine()
{
	return new Sandbox();
}
