
#pragma once

#include "Emulation.h"
#include "KeyEmulator.h"

/**
 * a key emulation class which always emulates press and release action
 * even if the key is just pressed (= not released).
 */
class PressAndReleaseDecorator : public Emulation {
private:
	std::auto_ptr<Emulation> emulation;

public:
	PressAndReleaseDecorator(std::auto_ptr<Emulation> &emulation);
	virtual ~PressAndReleaseDecorator();

	virtual void executeDown(const KeyEmulator &emulator, const KeyCondition &cond);
	virtual void executeUp(const KeyEmulator &emulator, const KeyCondition &cond);
};
