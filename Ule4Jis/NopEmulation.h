#pragma once

#include "Emulation.h"

class NopEmulation : public Emulation {
public:
	NopEmulation() {}
	virtual ~NopEmulation() {}
	virtual void executeDown(const KeyEmulator &emulator, const KeyCondition &cond) {}
	virtual void executeUp(const KeyEmulator &emulator, const KeyCondition &cond) {}
};
