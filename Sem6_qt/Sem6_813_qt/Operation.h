#pragma once
#include "Aircraft.h"

enum OperationType {Add, Remove};

class Operation
{
public:

	OperationType operationType;
	Aircraft* item;

	Operation();
	~Operation();
};

