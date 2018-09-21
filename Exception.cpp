# include "Exception.hpp"

const char *
Exception::Overflow::what(void) const throw() {
	return ("Overflow on a value.");
}

const char *
Exception::Underflow::what(void) const throw() {
	return ("Underflow on a value.");
}

const char *
Exception::Syntax::what(void) const throw() {
	return ("Syntax error.");
}

const char *
Exception::UnknownInstruction::what(void) const throw() {
	return ("Unknown instruction.");
}

const char *
Exception::PopOnEmptyStack::what(void) const throw() {
	return ("Try to pop an empty stack.");
}

const char *
Exception::FloatingPointError::what(void) const throw() {
	return ("Division/Modulo by 0.");
}

const char *
Exception::MissingExitInstruction::what(void) const throw() {
	return ("Missing exit instruction.");
}

const char *
Exception::AssertError::what(void) const throw() {
	return ("Assert instruction is not true.");
}

const char *
Exception::OperationOnEmptyStack::what(void) const throw() {
	return ("Operation can't be done because the stack have less than two operands.");
}

const char *
Exception::ModFloatingPoint::what(void) const throw() {
	return ("Can't make a modulo on floating point.");
}

const char *
Exception::PrintNonAscii::what(void) const throw() {
	return ("Try to print a non ascii character.");
}

const char *
Exception::PrintOnEmptyStack::what(void) const throw() {
	return ("Try to print on empty stack.");
}

const char *
Exception::FileDoesNotExist::what(void) const throw() {
	return ("File doesn't exist.");
}
