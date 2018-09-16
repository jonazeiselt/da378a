#include "stdafx.h"

#include "asgmt1.h"
#include "asgmt2.h"
#include "asgmt3.h"

#include <string>

/** 
 * lab4.cpp
 *
 * Author: Jonas Eiselt
 * Created 2017-09-20 
 */
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));

	// 1
	runAsgmt1();

	// 2
	runAsgmt2();

	// 3
	runAsgmt3();

    return 0;
}