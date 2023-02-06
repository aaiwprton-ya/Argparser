#include <iostream>
#include "argparser.h"

int main(int argc, char** argv)
{
	Argparser parser(argc, argv);
	std::cout << "Test is working: " << std::endl;
	parser.findArg(ArgType::ARGTYPE_STRING, "arg1", "a1");
	parser.findArg(ArgType::ARGTYPE_STRING, "arg2", "a2");
	std::cout << parser.testPrint();
	return 0;
}
