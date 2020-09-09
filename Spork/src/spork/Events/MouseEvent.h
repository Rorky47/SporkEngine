#pragma once

#include "spork/Events/Event.h"

#include <sstream>

namespace spork {

	class SPORK_API MouseMovedEvent : public Event
	{
	public: 
		MouseMovedEvent(float x,float y) 
			: MouseX(x), MouseY(y) {}
		inline float GetX() const { return MouseX; }
		inline float GetX() const { return MouseX; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved: " << MouseX << "| " << MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY( EventCategoryMouse | EventCategoryInput)
	private:
		float MouseX, MouseY;
	};
	class SPORK_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float x, float y)
			: XOffSet(x), YOffSet(y) {}
		inline float GetXOffSet() const { return XOffSet; }
		inline float GetYOffSet() const { return YOffSet; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled: " << GetXOffSet() << "| " << GetYOffSet();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScorlled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float XOffSet, YOffSet;
	};
	class SPORK_API MouseButtonEvent : public Event
	{
	public: 
		inline int GetMouseButton() const { return m_Button;  }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};


	class SPORK_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Clicked: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseClicked)
	};

	class SPORK_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Released: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseReleased)
	};
}