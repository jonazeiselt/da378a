#ifndef OPERATIONMULTIPLY_H
#define OPERATIONMULTIPLY_H

#include "Strategy.h"

class OperationMultiply : public Strategy 
{
public:
	~OperationMultiply() {}
	virtual int compute(int operandOne, int operandTwo) const;
};

#endif // !OPERATIONMULTIPLY_H
