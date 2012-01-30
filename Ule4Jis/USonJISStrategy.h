
#pragma once
#include "EmulationStrategy.h"

class USonJISStrategy : public EmulationStrategy {
public:
	virtual ~USonJISStrategy() {}
	virtual void getEmulationMap(EmulationMapType *dest);
};
