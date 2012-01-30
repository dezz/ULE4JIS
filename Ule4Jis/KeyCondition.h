#pragma once

class KeyCondition
{
private:
	BYTE lastVKey;
	static const int MOD_KEYS_COUNT = 6;
	bool modKeyState[MOD_KEYS_COUNT];
	static const BYTE MOD_KEYS[];

	bool isModKey(BYTE vkey) const;
	int getModKeyIndex(BYTE vkey) const;
	void initModKeyState();

public:
	KeyCondition();
	KeyCondition(BYTE lastVKey, bool shift = false);
	~KeyCondition();

	void changeKeyState(BYTE vkey, bool up);
	bool getModKeyState(BYTE vkey) const;

	int compare(const KeyCondition &obj) const;

	bool operator <(const KeyCondition &right) const;
	bool operator ==(const KeyCondition &right) const;
};
