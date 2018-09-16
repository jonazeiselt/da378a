#ifndef OPERATIONSUBTRACT_H
#define OPERATIONSUBTRACT_H

#include "Strategy.h"

class OperationSubtract : public Strategy
{
public:
	~OperationSubtract() {}
	virtual int compute(int operandOne, int operandTwo) const;
};

#endif // !OPERATIONSUBTRACT_H
