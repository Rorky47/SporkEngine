#pragma once

#include "Event.h"

#include <sstream>

namespace spork {

	class SPORK_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class SPORK_API KeyPressedEvent : public KeyEvent 
	{
	public:
		KeyPressedEvent(int keycode, int repeatNum)
			: KeyEvent(keycode), m_RepeatNum(repeatNum) {}

		inline int GetRepeatNum() const { return m_RepeatNum; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "KeyPressed: " << m_KeyCode << "(" << m_RepeatNum << " Times)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatNum;
	};

	class SPORK_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << m_KeyCode;
				return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}