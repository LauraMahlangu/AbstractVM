#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <vector>
# include "IOperand.hpp"
# include "eOperandType.hpp"


class Factory {
	
	typedef const IOperand *(Factory::*OperandFunc)(const std::string &) const;

	std::vector<OperandFunc> _func;
	Factory &	operator=(const Factory &rhs) const;

	const IOperand *
	createInt8(const std::string &value) const;
	const IOperand *
	createInt16(const std::string &value) const;
	const IOperand *
	createInt32(const std::string &value) const;
	const IOperand *
	createFloat(const std::string &value) const;
	const IOperand *
	createDouble(const std::string &value) const;

	public:
		
		~Factory(void);
		Factory(const Factory &rhs);
		Factory(void);

		const IOperand*
		createOperand(const eOperandType type, const std::string &value) const;
};

#endif
