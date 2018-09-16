#include "stdafx.h"
#include "Context.h"

Context::Context(Strategy* strategy)
{
	this->strategy = strategy;
}

Context::~Context()
{
	delete strategy;
}

int Context::compute(int operandOne, int operandTwo) const
{
	return strategy->compute(operandOne, operandTwo);
}
