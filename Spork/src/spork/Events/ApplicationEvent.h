#pragma once
#include "Event.h"

#include <sstream>

namespace Spork 
{
	class SPORK_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline usigned int GetWidth const{ return m_Width;}
		inline usigned int GetHeight const{ return m_Height; }


		EVENT_CLASS_TYPE()
		EVENT_CLASS_CATEGORY()
	private:
		unsigned int M_Width, M_Height;

	};

}