#pragma once
#include "Emulation.h"

class NormalKeyEmulation : public Emulation {
protected:
	BYTE vkey;

public:
	NormalKeyEmulation(BYTE vkey);
	virtual ~NormalKeyEmulation();

	virtual void executeDown(const KeyEmulator &emulator, const KeyCondition &cond);
	virtual void executeUp(const KeyEmulator &emulator, const KeyCondition &cond);
};
