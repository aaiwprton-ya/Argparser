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
{
	for (auto item: this->args)
	{
		switch (item.second.second[0])
		{
		case ArgType::ARGTYPE_INT:
			delete (int*)item.second.first;
			break;
		case ArgType::ARGTYPE_UINT:
			delete (unsigned int*)item.second.first;
			break;
		case ArgType::ARGTYPE_FLOAT:
			delete (float*)item.second.first;
			break;
		case ArgType::ARGTYPE_DOUBLE:
			delete (double*)item.second.first;
			break;
		case ArgType::ARGTYPE_CHAR:
			delete (char*)item.second.first;
			break;
		case ArgType::ARGTYPE_STRING:
			delete (std::string*)item.second.first;
			break;
		case ArgType::ARGTYPE_VECTOR:
			switch (item.second.second[1])
			{
			case ArgType::ARGTYPE_INT:
				delete (std::vector<int>*)item.second.first;
				break;
			case ArgType::ARGTYPE_UINT:
				delete (std::vector<unsigned int>*)item.second.first;
				break;
			case ArgType::ARGTYPE_FLOAT:
				delete (std::vector<float>*)item.second.first;
				break;
			case ArgType::ARGTYPE_DOUBLE:
				delete (std::vector<double>*)item.second.first;
				break;
			case ArgType::ARGTYPE_CHAR:
				delete (std::vector<char>*)item.second.first;
				break;
			case ArgType::ARGTYPE_STRING:
				delete (std::vector<std::string>*)item.second.first;
				break;
			default:
				break;
			}
			break;
		case ArgType::ARGTYPE_LIST:
			switch (item.second.second[1])
			{
			case ArgType::ARGTYPE_INT:
				delete (std::list<int>*)item.second.first;
				break;
			case ArgType::ARGTYPE_UINT:
				delete (std::list<unsigned int>*)item.second.first;
				break;
			case ArgType::ARGTYPE_FLOAT:
				delete (std::list<float>*)item.second.first;
				break;
			case ArgType::ARGTYPE_DOUBLE:
				delete (std::list<double>*)item.second.first;
				break;
			case ArgType::ARGTYPE_CHAR:
				delete (std::list<char>*)item.second.first;
				break;
			case ArgType::ARGTYPE_STRING:
				delete (std::list<std::string>*)item.second.first;
				break;
			default:
				break;
			}
			break;
		case ArgType::ARGTYPE_MAP:
			switch (item.second.second[1])
			{
			case ArgType::ARGTYPE_INT:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<int, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<int, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<int, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<int, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<int, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<int, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			case ArgType::ARGTYPE_UINT:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<unsigned int, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<unsigned int, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<unsigned int, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<unsigned int, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<unsigned int, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<unsigned int, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			case ArgType::ARGTYPE_FLOAT:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<float, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<float, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<float, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<float, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<float, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<float, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			case ArgType::ARGTYPE_DOUBLE:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<double, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<double, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<double, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<double, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<double, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<double, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			case ArgType::ARGTYPE_CHAR:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<char, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<char, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<char, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<char, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<char, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<char, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			case ArgType::ARGTYPE_STRING:
				switch (item.second.second[2])
				{
				case ArgType::ARGTYPE_INT:
					delete (std::map<std::string, int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_UINT:
					delete (std::map<std::string, unsigned int>*)item.second.first;
					break;
				case ArgType::ARGTYPE_FLOAT:
					delete (std::map<std::string, float>*)item.second.first;
					break;
				case ArgType::ARGTYPE_DOUBLE:
					delete (std::map<std::string, double>*)item.second.first;
					break;
				case ArgType::ARGTYPE_CHAR:
					delete (std::map<std::string, char>*)item.second.first;
					break;
				case ArgType::ARGTYPE_STRING:
					delete (std::map<std::string, std::string>*)item.second.first;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

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

bool Argparser::findArg(
		ArgType type, 
		std::string name, 
		std::string shortName, 
		bool required, 
		ArgType subType1, 
		ArgType subType2)
{
	size_t entry = this->s_data.find("--" + name);
	if (entry == std::string::npos)
	{
		entry = this->s_data.find("-" + shortName);
	}
	if (entry != std::string::npos)
	{
		if ((this->s_data.find("--" + name, entry + 1) != std::string::npos) || 
			(this->s_data.find("-" + shortName, entry + 1) != std::string::npos))
		{
			throw std::runtime_error("Double entry argument \"" + name + "\"");
		}
	} else
	{
		if (required)
		{
			throw std::runtime_error("Not faund required argument \"" + name + "\"");
		} else
		{
			return false;
		}
	}
	
	size_t valStart = this->s_data.find(" ", entry + 1) + 1;
	size_t valEnd = this->s_data.find("-", valStart + 1);
	if (valEnd == std::string::npos)
	{
		valEnd = this->s_data.length();
	}
	std::string_view value(this->s_data);
	value.remove_prefix(valStart);
	value.remove_suffix(this->s_data.length() - valEnd);
	
	this->args[name] = std::pair(
		this->m_constructArg(type, value, subType1, subType2), 
		std::vector<ArgType> {type, subType1, subType2});
	return true;
}

void Argparser::m_shielding()
{
	std::replace(s_data.begin(), s_data.end(), '=', ' ');
}

void* Argparser::m_constructArg(
		ArgType type, 
		std::string_view arg, 
		ArgType subType1, 
		ArgType subType2)
{
	void* result = nullptr;
	std::stringstream sstream(std::string {arg});
	switch (type)
	{
	case ArgType::ARGTYPE_INT:
		result = new int();
		sstream >> *(int*)result;
		break;
	case ArgType::ARGTYPE_UINT:
		result = new unsigned int();
		sstream >> *(unsigned int*)result;
		break;
	case ArgType::ARGTYPE_FLOAT:
		result = new float();
		sstream >> *(float*)result;
		break;
	case ArgType::ARGTYPE_DOUBLE:
		result = new double();
		sstream >> *(double*)result;
		break;
	case ArgType::ARGTYPE_CHAR:
		result = new char();
		sstream >> *(char*)result;
		break;
	case ArgType::ARGTYPE_STRING:
		result = new std::string();
		sstream >> *(std::string*)result;
		break;
	case ArgType::ARGTYPE_VECTOR:
		result = m_constructVector(subType1, arg);
		break;
	case ArgType::ARGTYPE_LIST:
		result = m_constructList(subType1, arg);
		break;
	case ArgType::ARGTYPE_MAP:
		result = m_constructMap(subType1, subType2, arg);
		break;
	default:
		throw std::runtime_error("Invalid argument type");
		break;
	}
	return result;
}

void* Argparser::m_constructVector(ArgType type, std::string_view arg)
{
	void* result = nullptr;
	switch (type)
	{
	case ArgType::ARGTYPE_INT:
		result = m_constructType<std::vector<int>, int>(arg);
		break;
	case ArgType::ARGTYPE_UINT:
		result = m_constructType<std::vector<unsigned int>, unsigned int>(arg);
		break;
	case ArgType::ARGTYPE_FLOAT:
		result = m_constructType<std::vector<float>, float>(arg);
		break;
	case ArgType::ARGTYPE_DOUBLE:
		result = m_constructType<std::vector<double>, double>(arg);
		break;
	case ArgType::ARGTYPE_CHAR:
		result = m_constructType<std::vector<char>, char>(arg);
		break;
	case ArgType::ARGTYPE_STRING:
		result = m_constructType<std::vector<std::string>, std::string>(arg);
		break;
	default:
		throw std::runtime_error("Invalid argument type");
		break;
	}
	return result;
}

void* Argparser::m_constructList(ArgType type, std::string_view arg)
{
	void* result = nullptr;
	switch (type)
	{
	case ArgType::ARGTYPE_INT:
		result = m_constructType<std::list<int>, int>(arg);
		break;
	case ArgType::ARGTYPE_UINT:
		result = m_constructType<std::list<unsigned int>, unsigned int>(arg);
		break;
	case ArgType::ARGTYPE_FLOAT:
		result = m_constructType<std::list<float>, float>(arg);
		break;
	case ArgType::ARGTYPE_DOUBLE:
		result = m_constructType<std::list<double>, double>(arg);
		break;
	case ArgType::ARGTYPE_CHAR:
		result = m_constructType<std::list<char>, char>(arg);
		break;
	case ArgType::ARGTYPE_STRING:
		result = m_constructType<std::list<std::string>, std::string>(arg);
		break;
	default:
		throw std::runtime_error("Invalid argument type");
		break;
	}
	return result;
}

void* Argparser::m_constructMap(ArgType type1, ArgType type2, std::string_view arg)
{
	void* result = nullptr;
	std::vector<std::string> args = m_parseArrayArgs(arg);
	switch (type1)
	{
	case ArgType::ARGTYPE_INT:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<int, int>, int, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType<std::map<int, unsigned int>, int, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<int, float>, int, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<int, double>, int, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<int, char>, int, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType<std::map<int, std::string>, int, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	case ArgType::ARGTYPE_UINT:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<unsigned int, int>, unsigned int, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType
				<std::map<unsigned int, unsigned int>, unsigned int, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<unsigned int, float>, unsigned int, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<unsigned int, double>, unsigned int, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<unsigned int, char>, unsigned int, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType
				<std::map<unsigned int, std::string>, unsigned int, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	case ArgType::ARGTYPE_FLOAT:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<float, int>, float, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType<std::map<float, unsigned int>, float, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<float, float>, float, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<float, double>, float, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<float, char>, float, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType<std::map<float, std::string>, float, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	case ArgType::ARGTYPE_DOUBLE:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<double, int>, double, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType<std::map<double, unsigned int>, double, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<double, float>, double, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<double, double>, double, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<double, char>, double, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType<std::map<double, std::string>, double, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	case ArgType::ARGTYPE_CHAR:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<char, int>, char, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType<std::map<char, unsigned int>, char, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<char, float>, char, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<char, double>, char, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<char, char>, char, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType<std::map<char, std::string>, char, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	case ArgType::ARGTYPE_STRING:
		switch (type2)
		{
		case ArgType::ARGTYPE_INT:
			result = m_constructMapType<std::map<std::string, int>, std::string, int>(arg);
			break;
		case ArgType::ARGTYPE_UINT:
			result = m_constructMapType
				<std::map<std::string, unsigned int>, std::string, unsigned int>(arg);
			break;
		case ArgType::ARGTYPE_FLOAT:
			result = m_constructMapType<std::map<std::string, float>, std::string, float>(arg);
			break;
		case ArgType::ARGTYPE_DOUBLE:
			result = m_constructMapType<std::map<std::string, double>, std::string, double>(arg);
			break;
		case ArgType::ARGTYPE_CHAR:
			result = m_constructMapType<std::map<std::string, char>, std::string, char>(arg);
			break;
		case ArgType::ARGTYPE_STRING:
			result = m_constructMapType
				<std::map<std::string, std::string>, std::string, std::string>(arg);
			break;
		default:
			throw std::runtime_error("Invalid argument type");
			break;
		}
		break;
	default:
		throw std::runtime_error("Invalid argument type");
		break;
	}
	return result;
}

std::vector<std::string> Argparser::m_parseArrayArgs(std::string_view arg)
{
	size_t beg, end;
	if ((end = arg.find("}")) != std::string::npos)
	{
		arg.remove_suffix(arg.length() - end);
	}
	if ((beg = arg.find("{")) != std::string::npos)
	{
		arg.remove_prefix(beg + 1);
	}
	std::vector<std::string> args = this->m_split(arg, ",");
	for (std::string& str: args)
	{
		str.erase(
			std::remove_if(
				str.begin(), 
				str.end(), 
				[] (char ch) -> bool {
					return std::isspace(ch);
				}), 
			str.end());
	}
	return args;
}

std::vector<std::string> Argparser::m_split(std::string_view input, std::string_view regex)
{
	std::string temp {input};
	std::regex reg(std::string {regex});
	std::sregex_token_iterator first {
		temp.begin(), 
		temp.end(), 
		reg, 
		-1}; 
	std::sregex_token_iterator last;
	return {first, last};
}

