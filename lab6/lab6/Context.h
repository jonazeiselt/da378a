#ifndef CONTEXT_H
#define CONTEXT_H

#include "OperationAdd.h"
#include "OperationSubtract.h"
#include "OperationMultiply.h"

class Context
{
private:
	Strategy* strategy = nullptr;
public:
	Context(Strategy* strategy);
	~Context();
	int compute(int operandOne, int operandTwo) const;
};

#endif // !CONTEXT_H

