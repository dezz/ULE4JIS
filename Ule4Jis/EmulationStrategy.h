#pragma once

#include "Emulation.h"
#include "KeyCondition.h"

typedef boost::ptr_map<KeyCondition, Emulation> EmulationMapType;

class EmulationStrategy {
public:
	virtual ~EmulationStrategy();
	virtual void getEmulationMap(EmulationMapType *dest) = 0;
};

inline EmulationStrategy::~EmulationStrategy() {}
