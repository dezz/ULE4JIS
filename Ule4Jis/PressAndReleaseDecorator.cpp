
#include "stdafx.h"
#include "PressAndReleaseDecorator.h"

PressAndReleaseDecorator::PressAndReleaseDecorator(std::auto_ptr<Emulation> &emulation) : emulation(emulation) {
}

PressAndReleaseDecorator::~PressAndReleaseDecorator() {
}

void PressAndReleaseDecorator::executeDown(const KeyEmulator &emulator, const KeyCondition &cond) {
	this->emulation->executeDown(emulator, cond);
	this->emulation->executeUp(emulator, cond);
}

void PressAndReleaseDecorator::executeUp(const KeyEmulator &emulator, const KeyCondition &cond) {
	this->emulation->executeDown(emulator, cond);
	this->emulation->executeUp(emulator, cond);
}
