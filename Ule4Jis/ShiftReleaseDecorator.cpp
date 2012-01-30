#include "stdafx.h"
#include "ShiftReleaseDecorator.h"
#include "KeyEmulator.h"

ShiftReleaseDecorator::ShiftReleaseDecorator(std::auto_ptr<Emulation> &emulation) : emulation(emulation) {
}

ShiftReleaseDecorator::~ShiftReleaseDecorator() {
}

void ShiftReleaseDecorator::executeDown(const KeyEmulator &emulator, const KeyCondition &cond) {
	// get current shift-key state
	bool lshift = cond.getModKeyState(VK_LSHIFT);
	bool rshift = cond.getModKeyState(VK_RSHIFT);

	// up shift key during key simulation
	if (lshift) {
		TRACE("up left shift\n");
		emulator.emulateKey(VK_LSHIFT, true);
	}
	if (rshift) {
		TRACE("up right shift\n");
		emulator.emulateKey(VK_RSHIFT, true);
	}

	this->emulation->executeDown(emulator, cond);

	// restore shift-key state
	if (lshift) {
		emulator.emulateKey(VK_LSHIFT);
	}
	if (rshift) {
		emulator.emulateKey(VK_RSHIFT);
	}
}

void ShiftReleaseDecorator::executeUp(const KeyEmulator &emulator, const KeyCondition &cond) {
	this->emulation->executeUp(emulator, cond);
}
