#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <string>
#include <string_view>
#include <map>
#include <algorithm>
#include <exception>

enum class ArgType : uint8_t
{
	ARGTYPE_INT,
	ARGTYPE_UINT, 
	ARGTYPE_FLOAT, 
	ARGTYPE_DOUBLE, 
	ARGTYPE_CHAR, 
	ARGTYPE_STRING, 
	ARGTYPE_VECTOR, 
	ARGTYPE_LIST, 
	ARGTYPE_MAP
};

class Argparser
{
	std::string s_data;
	std::map<std::string, std::pair<ArgType, std::string_view>> args;
public:
	Argparser();
	Argparser(std::string_view data);
	Argparser(int argc, char** argv);
	~Argparser();
public:
	void m_init(std::string_view data);
	void m_init(int argc, char** argv);
	void findArg(ArgType type, std::string name, std::string shortName);
	std::string testPrint();
	void getArg(std::string_view name, void* p_dataPlace);
private:
	void m_shielding();
};

#endif // ARGPARSER_H
