#include "sppch.h"
#include "platform/Windows/WindowsWindow.h"

#include "Spork/Events/ApplicationEvent.h"
#include "Spork/Events/MouseEvent.h"
#include "Spork/Events/KeyEvent.h"

namespace spork 
{

	static bool WindowInit = false;
	
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}
	WindowsWindow::WindowsWindow(const WindowProps& props) 
	{
		
	}
	WindowsWindow::~WindowsWindow()
	{

	}
}