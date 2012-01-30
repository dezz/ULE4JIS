#pragma once
#include "Emulation.h"
#include "KeyEmulator.h"

class ShiftPressDecorator : public Emulation {
private:
	std::auto_ptr<Emulation> emulation;

public:
	ShiftPressDecorator(std::auto_ptr<Emulation> &emulation);
	virtual ~ShiftPressDecorator();
	virtual void executeDown(const KeyEmulator &emulator, const KeyCondition &cond);
	virtual void executeUp(const KeyEmulator &emulator, const KeyCondition &cond);
};
