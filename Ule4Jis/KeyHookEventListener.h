#pragma once

#include "KeyHookEventArgs.h"

class KeyHookEventListener
{
public:
	virtual ~KeyHookEventListener();

	/** return true to cancel input event */
	virtual bool onKeyHookEvent(const KeyHookEventArgs &args) = 0;
};

inline KeyHookEventListener::~KeyHookEventListener() {}
