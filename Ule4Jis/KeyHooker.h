#pragma once

#include "KeyHookEventListener.h"

class KeyHooker
{
private:
	static HHOOK hookHandle;
	static KeyHooker *thisPtr;

	KeyHookEventListener *listener;

	static LRESULT CALLBACK hookProc(int code, WPARAM wparam, LPARAM lparam);

public:
	KeyHooker(KeyHookEventListener *listener);
	~KeyHooker();
};
