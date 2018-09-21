#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <list>
# include "eCommandType.hpp"
# include "IOperand.hpp"

class Parser {
	public:
		Parser();
		~Parser();

		eCommandType							getCommandType(const std::string &str);
		eOperandType 							getOperandType(const std::string &str);
		std::string								getOperandValue(const std::string &str);

};

#endif
