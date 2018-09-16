#include "stdafx.h"
#include "Context.h"

#include <crtdbg.h>
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int operandOne = 10, operandTwo = 3;

	Context *context = new Context(new OperationSubtract());
	std::cout << operandOne << " - " << operandTwo << " = " << context->compute(operandOne, operandTwo) << std::endl;
	delete context;

	context = new Context(new OperationAdd());
	std::cout << operandOne << " + " << operandTwo << " = " << context->compute(operandOne, operandTwo) << std::endl;
	delete context;

	context = new Context(new OperationMultiply());
	std::cout << operandOne << " * " << operandTwo << " = " << context->compute(operandOne, operandTwo) << std::endl;
	delete context;

	return 0;
}
