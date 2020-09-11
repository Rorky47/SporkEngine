#pragma once
#include "Events/Event.h"
namespace spork 
{
	struct WindowProps 
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Spork Engine", unsigned int width = 600, unsigned int height = 600)
			:Title(title), Width(width), Height(height) {}
	};
	class SPORK_API	Window {

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}