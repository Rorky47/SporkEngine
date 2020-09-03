#pragma once

#include <functional>
#include <string>

#include "src/spork/Core.h"


namespace spork {

	enum class EventType 
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdated, AppRender,
		Keypressed, KeyReleased,
		MousebouttonPressed, MouseButtonReleased,MouseMoved, MouseScorlled
	};

	enum class EventCategory 
	{
		None = 0,
		EventCatagoryApplication   = BIT(0),
		EventCatagoryInput         = BIT(1),
		EventCatagoryKeboard       = BIT(2),
		EventCatagoryMouse         = BIT(3),
		EventCatagoryMouseButton   = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type;}\
								virtual EventType GetStaticType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	class SPORK_API Event
	{
		friend class EventDispatcher;
	public:
		//ToString and get name put in debug only mode
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCatagoryFlags(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispacher
	{
		template<typename T>
			using EvenFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) 
			: m_Event(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func) 
		{
			if (m_Event.GetEventTyoe() == T::GetStaticType()) 
			{
				m_Event.m_Handled = func(*(T*)&M_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};


}