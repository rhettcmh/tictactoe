#include <iostream>
#include "testScript.h"

int main()
{
	// Creates a test object, runs all tests
	TestScript *test = new TestScript();
	test->runTests();

	return 0;
}