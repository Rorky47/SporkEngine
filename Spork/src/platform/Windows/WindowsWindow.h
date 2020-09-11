#pragma once

#include "spork/Window.h"

namespace spork {

	class WindowsWindow : public Window 
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override{ return Width; }
		unsigned int GetWidth() const override { return Height; }


		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		//virtual void* GetNativeWindow() const { return m_Window;  }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		std::string const window_class = "Window Class";
		HWND m_hwnd;
	};
}