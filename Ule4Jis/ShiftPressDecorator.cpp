
#include "stdafx.h"
#include "ShiftPressDecorator.h"

ShiftPressDecorator::ShiftPressDecorator(std::auto_ptr<Emulation> &emulation) : emulation(emulation) {
}

ShiftPressDecorator::~ShiftPressDecorator() {
}

void ShiftPressDecorator::executeDown(const KeyEmulator &emulator, const KeyCondition &cond) {
	emulator.emulateKey(VK_LSHIFT);
	this->emulation->executeDown(emulator, cond);
	emulator.emulateKey(VK_LSHIFT, true);
}

void ShiftPressDecorator::executeUp(const KeyEmulator &emulator, const KeyCondition &cond) {
	this->emulation->executeUp(emulator, cond);
}
