
#include "stdafx.h"
#include "KeyHookEventArgs.h"

KeyHookEventArgs::KeyHookEventArgs(HHOOK hookHandle, LPKBDLLHOOKSTRUCT khs)
		: hookHandle(hookHandle),
		vkey((BYTE)khs->vkCode),
		up((khs->flags & LLKHF_UP) ? true : false),
		extendedKey((khs->flags & LLKHF_EXTENDED) ? true : false),
		extraInfo(khs->dwExtraInfo) {
}
