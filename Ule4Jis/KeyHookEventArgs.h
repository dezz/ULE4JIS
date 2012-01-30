
#pragma once

class KeyHookEventArgs {
private:
	HHOOK hookHandle;
	BYTE vkey;
	bool up;
	bool extendedKey;
	ULONG_PTR extraInfo;

public:
	KeyHookEventArgs(HHOOK hookHandle, LPKBDLLHOOKSTRUCT khs);

	HHOOK getHookHandle() const { return this->hookHandle; }
	BYTE getVKey() const { return this->vkey; }
	bool isUp() const { return this->up; }
	bool isExtendedKey() const { return this->extendedKey; }
	ULONG_PTR getExtraInfo() const { return this->extraInfo; }
};
