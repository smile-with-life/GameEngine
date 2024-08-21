#pragma once

#include<GE/Core.h>

#include<string>
#include<functional>
#include<sstream>

namespace GE
{
enum class EventType
{
    None=0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};
enum EventCategory
{
    None = 0,
    EventCategoryApplication        = BIT(0),
    EventCategoryInput              = BIT(1),
    EventCategoryKeyboard           = BIT(2),
    EventCategoryMouse              = BIT(3),
    EventCategoryMouseButton        = BIT(4)
};

#define EVENT_CLASS_TYPE(type) \
			static EventType GetStaticType(){ return EventType::##type; }\
			virtual EventType GetEventType() const override { return GetStaticType(); }\
			virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)\
			virtual int GetCategoryFlags() const override { return category; }
class Event
{
	friend class EventDispatcher;
public:
	virtual ~Event() = default;
											
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int GetCategoryFlags() const = 0;
	virtual std::string ToString() const { return GetName(); }			

	inline bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;							
	}

protected:
    bool m_Handled = false;
};
class EventDispatcher
{
private:
	Event& m_Event;

	template<class T>												
	using EventFunc = std::function<bool(T&)>;
public:
	EventDispatcher(Event& event)
		:m_Event(event)
	{}
	template<class T>			
	bool Dispatch(EventFunc<T> func)
	{									
		if (m_Event.GetEventType() == T::GetStaticType())				
		{									
			m_Event.m_Handled = func(static_cast<T&>(m_Event));						
			return true;												
		}
		return false;
	}
};

inline std::ostream& operator<<(std::ostream& os, const Event& event)
{
	return os << event.ToString();
}

}//namespace GE
