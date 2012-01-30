#pragma once

#include "KeyCondition.h"

class KeyEmulator;

class Emulation {
public:
	virtual ~Emulation();
	virtual void executeDown(const KeyEmulator &emulator, const KeyCondition &cond) = 0;
	virtual void executeUp(const KeyEmulator &emulator, const KeyCondition &cond) = 0;
};

inline Emulation::~Emulation() {}
