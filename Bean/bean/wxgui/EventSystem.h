#pragma once
#ifndef BEAN_WXGUI_EVENTSYSTEM_H
#define BEAN_WXGUI_EVENTSYSTEM_H
#include <vector>
class Object_;
class UserDelegate;

using ListenerRList = std::vector<Object_*>;
using ListenerVList = std::vector<UserDelegate*>;
class EventSystem {
public:
	/**
	 * 全てのリスナーを保護します.
	 * @param rlist
	 * @param vlist
	 */
	static void markRef(ListenerRList rlist, ListenerVList vlist);

	static void postEvent(ListenerVList vlist, std::vector<Object_*> args);
private:
	EventSystem();
	~EventSystem();
};
#endif // !BEAN_WXGUI_EVENTSYSTEM_H
