# include "AbstractVM.hpp"
# include "Exception.hpp"
# include <iostream>
# include <cstring>
# include "eOperandType.hpp"

AbstractVM::AbstractVM() {
    this->_allowed.push_back("push");	
	this->_allowed.push_back("pop");	
	this->_allowed.push_back("dump");	
	this->_allowed.push_back("assert");	
	this->_allowed.push_back("add");	
	this->_allowed.push_back("sub");	
	this->_allowed.push_back("mul");	
	this->_allowed.push_back("div");	
	this->_allowed.push_back("mod");	
	this->_allowed.push_back("print");	
	this->_allowed.push_back("exit");

	this->_type.push_back("int8");
	this->_type.push_back("int16");
	this->_type.push_back("int32");
	this->_type.push_back("float");
	this->_type.push_back("double");
}

AbstractVM::~AbstractVM() {}

void		AbstractVM::readFile(std::string filename) {
    filename.c_str();
	std::ifstream	file(filename);
	std::string 	line;

	if (!(file.good())) {
		throw Exception::FileDoesNotExist();
	} else {
		while (getline(file, line))
		{
			if (line.size() > 0) {
					this->_instructions.push_back(line);
				if (strncmp(line.c_str(), "exit", 4) == 0)
					break;		
			}
		}
	}
	file.close();
}

void		AbstractVM::run() {

	for (std::list<std::string>::iterator it = this->_instructions.begin(); it != this->_instructions.end(); ++it){
		std::string line;
		line = *it;

		if (line[0] != ';') {
			std::string instruction = line.substr(0, line.find(" "));
			
			
			std::list<std::string>::iterator ins;
			ins = std::find(this->_allowed.begin(), this->_allowed.end(), instruction);
			if (ins == this->_allowed.end())
				throw Exception::UnknownInstruction();

			std::string instruct = line.substr(0, line.find('('));
			if (instruction == "push" || instruction == "assert") {
				std::string	temp = line.substr(line.find(' ') + 1);
				std::string type(temp.begin(), std::find(temp.begin(), temp.end(), '('));

			 std::list<std::string>::iterator inst;
			 inst = std::find(this->_type.begin(),this->_type.end(), type);
			 if (inst == this->_type.end())
				throw Exception::UnknownInstruction();
			}
			std::string instr = line.substr(0, line.find('('));
			if (instruction == "push" || instruction == "assert") {
				std::string	temp = line.substr(line.find(' ') + 1);
			if (line.find('(') == std::string::npos  || line.find(')') == std::string::npos)
				throw Exception::UnknownInstruction();
			}
		}
	}
	 std::list<std::string>::iterator i = this->_instructions.end();
	 i--;
	if (*i != "exit")
		std::cout << "No Exit instuction found" << std::endl;
}

std::list<std::string>		AbstractVM::getlist(void) {
	return (this->_instructions);
}

void 								AbstractVM::runprog() {
	std::list<std::string>::const_iterator		ite;
	std::list<std::string>::const_iterator		iter;

	ite = this->_instructions.begin();
	iter = this->_instructions.end();

	while (ite != iter) {
		switch (_tst.getCommandType(*ite)) {
			case Error:
				throw Exception::UnknownInstruction();
			case Dump:
				this->dump();
				break ;
			case Push:
				this->push(*ite);
				break ;
			case Pop:
				this->pop();
				break ;
			case Assert:
				this->assert(*ite);
				break ;
			case Add:
				this->add();
				break ;
			case Sub:
				this->sub();
				break ;
			case Mul:
				this->mul();
				break ;
			case Div:
				this->div();
				break ;
			case Mod:
				this->mod();
				break ;
			case Print:
				this->print();
				break ;
			default:
				break ;
		}
		ite++;
	}
}
	
void 								AbstractVM::push(const std::string &str) {

	eOperandType						operand_type = _tst.getOperandType(str);
	std::string							value = _tst.getOperandValue(str);
	switch (operand_type) {
		case error:
			throw Exception::Syntax();
		default:
			_vassel.push_back(_factory.createOperand(operand_type, value));
		break;
	}

}

void								AbstractVM::assert(const std::string &str) {
if (!_vassel.size())
		throw Exception::AssertError();

	std::string						value = _tst.getOperandValue(str);
	const IOperand					&operand = **(_vassel.begin());

	if (value != operand.toString())
		throw Exception::AssertError();
}

void								AbstractVM::dump(void)const{
	std::list<const IOperand *>::const_iterator ite;
	std::list<const IOperand *>::const_iterator iter;

	ite = _vassel.begin();
	iter = _vassel.end();
	while (ite != iter){
		std::cout << (*ite)->toString() << std::endl;
		ite++;
	}
}
	
void								AbstractVM::pop(void) {
	if (_vassel.empty())
		throw Exception::PopOnEmptyStack();
	_vassel.pop_back();

}
							
void								AbstractVM::add(void) {
	const IOperand					*first = NULL;
	const IOperand					*second = NULL;

	if (_vassel.size() < 2)
		throw Exception::OperationOnEmptyStack();
	first = _vassel.back();
	_vassel.pop_back();
	second = _vassel.back();
	_vassel.pop_back();
	_vassel.push_back(*first + *second);
}

void								AbstractVM::sub(void) {
	const IOperand					*first = NULL;
	const IOperand					*second = NULL;

	if (_vassel.size() < 2)
		throw Exception::OperationOnEmptyStack();
	first = _vassel.back();
	_vassel.pop_back();
	second = _vassel.back();
	_vassel.pop_back();
	_vassel.push_back(*first - *second);
}

void								AbstractVM::div(void) {
	const IOperand					*first = NULL;
	const IOperand					*second = NULL;

	if (_vassel.size() < 2)
		throw Exception::OperationOnEmptyStack();
	first = _vassel.back();
	_vassel.pop_back();
	second = _vassel.back();
	_vassel.pop_back();
	_vassel.push_back(*first / *second);
}

void								AbstractVM::mul(void) {
	const IOperand					*first = NULL;
	const IOperand					*second = NULL;

	if (_vassel.size() < 2){
		throw Exception::OperationOnEmptyStack();
	}
	first = _vassel.back();
	_vassel.pop_back();
	second = _vassel.back();
	_vassel.pop_back();
	_vassel.push_back(*first * *second);
}

void								AbstractVM::mod(void) {
	const IOperand					*first = NULL;
	const IOperand					*second = NULL;

	if (_vassel.size() < 2)
		throw Exception::OperationOnEmptyStack();
	first = _vassel.back();
	_vassel.pop_back();
	second = _vassel.back();
	_vassel.pop_back();
	_vassel.push_back(*first % *second);
}

void 							AbstractVM::print() const{
	const IOperand					*ioperand = NULL;
	const Operand<char>				*operand = NULL;

	if (_vassel.empty())
		throw Exception::PrintOnEmptyStack();
	ioperand = _vassel.back();
	if (ioperand->getType() != Int8)
		throw Exception::PrintNonAscii();
	operand = static_cast<const Operand<char> *>(ioperand);
	std::cout << operand->getValue() << std::endl;
}
