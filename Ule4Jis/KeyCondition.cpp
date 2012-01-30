#include "StdAfx.h"
#include "KeyCondition.h"

const BYTE KeyCondition::MOD_KEYS[] = {
	VK_LSHIFT,
	VK_RSHIFT,
	VK_LCONTROL,
	VK_RCONTROL,
	VK_LMENU,
	VK_RMENU
};

KeyCondition::KeyCondition() {
	initModKeyState();
}

KeyCondition::KeyCondition(BYTE vkey, bool shift) : lastVKey(vkey) {
	initModKeyState();
	if (shift) {
		this->modKeyState[getModKeyIndex(VK_LSHIFT)] = true;
	}
}

KeyCondition::~KeyCondition() {
}

void KeyCondition::initModKeyState() {
	for (int i = 0; i < KeyCondition::MOD_KEYS_COUNT; i++) {
		this->modKeyState[i] = false;
	}
}

void KeyCondition::changeKeyState(BYTE vkey, bool up) {
	this->lastVKey = vkey;

	if (isModKey(vkey)) {
		this->modKeyState[getModKeyIndex(vkey)] = !up;
	}
}

int KeyCondition::getModKeyIndex(BYTE vkey) const {
	ASSERT(isModKey(vkey));
	for (int i = 0; i < KeyCondition::MOD_KEYS_COUNT; i++) {
		if (KeyCondition::MOD_KEYS[i] == vkey) {
			return i;
		}
	}
	ASSERT(false);
	return -1;
}

bool KeyCondition::isModKey(BYTE vkey) const {
	for (int i = 0; i < sizeof(KeyCondition::MOD_KEYS); i++) {
		if (vkey == KeyCondition::MOD_KEYS[i]) {
			return true;
		}
	}
	return false;
}

bool KeyCondition::getModKeyState(BYTE vkey) const {
	ASSERT(isModKey(vkey));
	return this->modKeyState[getModKeyIndex(vkey)];
}

int KeyCondition::compare(const KeyCondition &obj) const {
	// compare with ignoring mod-key position

	// get mod-key state (exclude ctrl-key)
	bool this_shift = getModKeyState(VK_LSHIFT) || getModKeyState(VK_RSHIFT);
	bool this_alt = getModKeyState(VK_LMENU) || getModKeyState(VK_RMENU);

	bool obj_shift = obj.getModKeyState(VK_LSHIFT) || obj.getModKeyState(VK_RSHIFT);
	bool obj_alt = obj.getModKeyState(VK_LMENU) || obj.getModKeyState(VK_RMENU);

	int this_value = 0;
	this_value |= this_shift ? 1 : 0;
	this_value <<= 1;
	this_value |= this_alt ? 1 : 0;
	this_value <<= 8;
	this_value |= this->lastVKey;

	int obj_value = 0;
	obj_value |= obj_shift ? 1 : 0;
	obj_value <<= 1;
	obj_value |= obj_alt ? 1 : 0;
	obj_value <<= 8;
	obj_value |= obj.lastVKey;

	if (this_value > obj_value) {
		return 1;
	} else if (this_value < obj_value) {
		return -1;
	} else {
		return 0;
	}
}

bool KeyCondition::operator <(const KeyCondition &right) const {
	return (compare(right) < 0);
}

bool KeyCondition::operator ==(const KeyCondition &right) const {
	return (compare(right) == 0);
}
