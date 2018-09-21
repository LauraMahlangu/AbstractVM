# include <iostream>
# include <fstream>
# include <regex>
# include <unistd.h>
# include "eOperandType.hpp"
# include "Exception.hpp"
# include "Parser.hpp"

Parser::Parser() {}
Parser::~Parser() {}

eCommandType						Parser::getCommandType(const std::string &str) {
	if (str.substr(0, 5) == "push ")
		return Push;
	if (str.substr(0, 7) == "assert ")
		return Assert;
	if (str.substr(0, 1) == ";")
		return Comment;
	if (str.substr(0, 3) == "pop")
		return Pop;
	if (str.substr(0, 4) == "dump")
		return Dump;
	if (str.substr(0, 3) == "add")
		return Add;
	if (str.substr(0, 3) == "sub")
		return Sub;
	if (str.substr(0, 3) == "mul")
		return Mul;
	if (str.substr(0, 3) == "div")
		return Div;
	if (str.substr(0, 3) == "mod")
		return Mod;
	if (str.substr(0, 5) == "print")
		return Print;
	if (str.substr(0, 4) == "exit")
		return Exit;
	if (str.substr(0, 2) == ";;")
		return End;
	return Error;
}

eOperandType							Parser::getOperandType(const std::string &str) {
	std::string							operand_type = str.substr(str.find(' ') + 1, str.size());

	if (operand_type.substr(0, 4) == "int8")
		return Int8;
	if (operand_type.substr(0, 5) == "int16")
		return Int16;
	if (operand_type.substr(0, 5) == "int32")
		return Int32;
	if (operand_type.substr(0, 5) == "float")
		return Float;
	if (operand_type.substr(0, 6) == "double")
		return Double;
	return error;
}

std::string								Parser::getOperandValue(const std::string &str) {
	std::string							operand_value = str.substr(str.find('(') + 1, str.size());
	const char							*checker;
	std::regex							digit("^[0-9.-]*$");

	if (operand_value.find(')') != std::string::npos) {
		checker = operand_value.substr(operand_value.find(')') + 1, std::string::npos).c_str();
		for (int i = 0; checker[i]; i++) {
			if (checker[i] == ';')
				break ;
			if (checker[i] != ' ')
				throw Exception::Syntax();
		}
	}
	
	operand_value = operand_value.substr(0, operand_value.find(')'));
	if (!std::regex_match(operand_value, digit))
		throw Exception::Syntax();
	return operand_value;
}
