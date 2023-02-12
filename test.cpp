#include <iostream>
#include "argparser.h"

int main(int argc, char** argv)
{
	Argparser parser(argc, argv);
	
	parser.findArg(ArgType::ARGTYPE_INT, "arg1", "a1");
	parser.findArg(ArgType::ARGTYPE_UINT, "arg2", "a2");
	parser.findArg(ArgType::ARGTYPE_FLOAT, "arg3", "a3");
	parser.findArg(ArgType::ARGTYPE_CHAR, "arg4", "a4");
	parser.findArg(ArgType::ARGTYPE_STRING, "arg5", "a5");
	parser.findArg(ArgType::ARGTYPE_VECTOR, "arg6", "a6", true, ArgType::ARGTYPE_INT);
	parser.findArg(ArgType::ARGTYPE_LIST, "arg7", "a7", true, ArgType::ARGTYPE_STRING);
	parser.findArg(
		ArgType::ARGTYPE_MAP, "arg8", "a8", true, ArgType::ARGTYPE_INT, ArgType::ARGTYPE_STRING);
	
	int* arg1 = parser.getArg("arg1", &arg1);
	unsigned int* arg2 = parser.getArg("arg2", &arg2);
	float* arg3 = parser.getArg("arg3", &arg3);
	char* arg4 = parser.getArg("arg4", &arg4);
	std::string* arg5 = parser.getArg("arg5", &arg5);
	std::vector<int>* arg6 = parser.getArg("arg6", &arg6);
	std::list<std::string>* arg7 = parser.getArg("arg7", &arg7);
	std::map<int, std::string>* arg8 = parser.getArg("arg8", &arg8);
	
	std::cout << "Arg1: " << *arg1 << std::endl;
	std::cout << "Arg2: " << *arg2 << std::endl;
	std::cout << "Arg3: " << *arg3 << std::endl;
	std::cout << "Arg4: " << *arg4 << std::endl;
	std::cout << "Arg5: " << *arg5 << std::endl;
	std::cout << "Arg6: {";
	bool flag = false;
	for (int item: *arg6)
	{
		if (flag)
		{
			std::cout << ", ";
		}
		std::cout << item;
		flag = true;
	}
	std::cout << "}" << std::endl;
	
	std::cout << "Arg7: {";
	flag = false;
	for (std::string item: *arg7)
	{
		if (flag)
		{
			std::cout << ", ";
		}
		std::cout << item;
		flag = true;
	}
	std::cout << "}" << std::endl;
	
	std::cout << "Arg8: {";
	flag = false;
	for (auto item: *arg8)
	{
		if (flag)
		{
			std::cout << ", ";
		}
		std::cout << item.first << ":" << item.second;
		flag = true;
	}
	std::cout << "}" << std::endl;
	
	std::cout << "Test is success" << std::endl;
	return 0;
}
