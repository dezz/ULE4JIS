#include "StdAfx.h"
#include "KeyEmulator.h"

KeyEmulator::KeyEmulator(EmulationStrategy *strategy) {
	// initialize emulation map
	changeEmulationStrategy(strategy);
}

KeyEmulator::~KeyEmulator() {
}

void KeyEmulator::changeEmulationStrategy(EmulationStrategy *strategy) {
	strategy->getEmulationMap(&this->emulationMap);
}

void KeyEmulator::start() {
	ASSERT(this->hooker.get() == NULL);
	this->hooker.reset(new KeyHooker(this));
}

void KeyEmulator::end() {
	ASSERT(this->hooker.get() != NULL);
	this->hooker.reset();
}

bool KeyEmulator::onKeyHookEvent(const KeyHookEventArgs &args) {

	if (args.getExtraInfo() == (ULONG_PTR)this) {
		// ignore emulation input
		return false;
	}

	// set condition object
	this->keyCondition.changeKeyState(args.getVKey(), args.isUp());

	// find emulation command object from map
	EmulationMapType::iterator it = this->emulationMap.find(this->keyCondition);
	if (it != this->emulationMap.end()) {
		// execute it
		if (args.isUp()) {
			it->second->executeUp(*this, this->keyCondition);
		} else {
			it->second->executeDown(*this, this->keyCondition);
		}

		return true; // cancel input
	}

	return false;
}

void KeyEmulator::emulateKey(BYTE vkey, bool up) const {
	DWORD flags = up ? KEYEVENTF_KEYUP : 0;
	if (isExtendedKey(vkey)) {
		flags |= KEYEVENTF_EXTENDEDKEY;
	}
	::keybd_event(vkey, 0, flags, (ULONG_PTR)this);
}

bool KeyEmulator::isExtendedKey(BYTE vkey) const {
	switch (vkey) {
		case VK_RCONTROL:
		case VK_RMENU:
		case VK_RSHIFT:
		case VK_INSERT:
		case VK_DELETE:
		case VK_HOME:
		case VK_END:
		case VK_PRIOR:
		case VK_NEXT:
		case VK_UP:
		case VK_DOWN:
		case VK_RIGHT:
		case VK_LEFT:
		case VK_NUMLOCK:
		case VK_CANCEL:
		case VK_PRINT:
		case VK_DIVIDE:
		case VK_SEPARATOR:
			return true;
		default:
			return false;
	}
}
