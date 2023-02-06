#include "argparser.h"

Argparser::Argparser()
{}

Argparser::Argparser(std::string_view data)
	: s_data(data)
{}

Argparser::Argparser(int argc, char** argv)
{
	this->m_init(argc, argv);
}

Argparser::~Argparser()
{}

void Argparser::m_init(std::string_view data)
{
	this->s_data = data;
	this->m_shielding();
}

void Argparser::m_init(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		this->s_data += argv[i];
		this->s_data += ' ';
	}
	this->m_shielding();
}

void Argparser::findArg(ArgType type, std::string name, std::string shortName)
{
	size_t entry = this->s_data.find("--" + name);
	//size_t argStart = entry + 2;
	if (entry == std::string::npos)
	{
		entry = this->s_data.find("-" + shortName);
		//argStart = entry + 1;
	}
	if (entry != std::string::npos)
	{
		if ((this->s_data.find("--" + name, entry + 1) != std::string::npos) || 
			(this->s_data.find("-" + shortName, entry + 1) != std::string::npos))
		{
			throw std::runtime_error("Double entry argument" + name);
		}
	} else
	{
		throw std::runtime_error("Nor faund argument " + name);
	}
	
	//size_t argEnd = this->s_data.find(" ", argStart + 1);
	//std::string_view arg(this->s_data);
	//arg.remove_prefix(argStart);
	//arg.remove_suffix(this->s_data.length() - argEnd);
	
	size_t valStart = this->s_data.find(" ", entry + 1) + 1;
	size_t valEnd = this->s_data.find("-", valStart + 1);
	if (valEnd == std::string::npos)
	{
		valEnd = this->s_data.length();
	}
	std::string_view value(this->s_data);
	value.remove_prefix(valStart);
	value.remove_suffix(this->s_data.length() - valEnd);
	
	this->args[name] = std::pair(type, value);
}

std::string Argparser::testPrint()
{
	std::string result;
	for (auto item: this->args)
	{
		result += item.first + ": " + std::string(item.second.second) + "\n";
	}
	return result;
}

void Argparser::getArg(std::string_view name, void* p_dataPlace)
{
	
}

void Argparser::m_shielding()
{
	std::replace(s_data.begin(), s_data.end(), '=', ' ');
}

