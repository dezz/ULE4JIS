
#include "stdafx.h"
#include "NormalKeyEmulation.h"
#include "KeyEmulator.h"

NormalKeyEmulation::NormalKeyEmulation(BYTE vkey) : vkey(vkey) {
}

NormalKeyEmulation::~NormalKeyEmulation() {
}

void NormalKeyEmulation::executeDown(const KeyEmulator &emulator, const KeyCondition &cond) {
	emulator.emulateKey(this->vkey);
}

void NormalKeyEmulation::executeUp(const KeyEmulator &emulator, const KeyCondition &cond) {
	emulator.emulateKey(this->vkey, true);
}

