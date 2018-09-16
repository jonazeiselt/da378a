#ifndef OPERATIONADD_H
#define OPERATIONADD_H

#include "Strategy.h"

class OperationAdd : public Strategy
{
public:
	~OperationAdd() {}
	virtual int compute(int operandOne, int operandTwo) const;
};

#endif // !OPERATIONADD_H

