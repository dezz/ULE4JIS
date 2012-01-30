#include "StdAfx.h"
#include "KeyHooker.h"

HHOOK KeyHooker::hookHandle = NULL;
KeyHooker *KeyHooker::thisPtr = NULL;


KeyHooker::KeyHooker(KeyHookEventListener *listener) : listener(listener)
{
	ASSERT(KeyHooker::hookHandle == NULL);

	// save this ptr
	KeyHooker::thisPtr = this;

	// hook start
	KeyHooker::hookHandle = ::SetWindowsHookEx(WH_KEYBOARD_LL, &KeyHooker::hookProc,
		::AfxGetInstanceHandle(), 0);
	if (!KeyHooker::hookHandle) {
		throw new CUserException();
	}
}

KeyHooker::~KeyHooker()
{
	if (KeyHooker::hookHandle) {
		::UnhookWindowsHookEx(KeyHooker::hookHandle);
		KeyHooker::hookHandle = NULL;
	}
}

LRESULT CALLBACK KeyHooker::hookProc(int code, WPARAM wparam, LPARAM lparam) {
	if (code < 0) {
		return ::CallNextHookEx(KeyHooker::hookHandle, code, wparam, lparam);
	}

	LPKBDLLHOOKSTRUCT khs = (LPKBDLLHOOKSTRUCT)lparam;
	TRACE("key event recieved. scan: %x, vkey: %x, up: %s\n", khs->scanCode, khs->vkCode, (khs->flags & LLKHF_UP) ? "true" : "false");

	KeyHookEventArgs args(KeyHooker::hookHandle, (LPKBDLLHOOKSTRUCT)lparam);
	if (KeyHooker::thisPtr->listener->onKeyHookEvent(args)) {
		return TRUE;
	} else {
		return ::CallNextHookEx(KeyHooker::hookHandle, code, wparam, lparam);
	}
}
