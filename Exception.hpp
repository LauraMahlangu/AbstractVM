#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <iostream>

namespace Exception {
	class Overflow: public std::exception {
		public:
			const char 				*what(void) const throw();
	};

	class Underflow: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class Syntax: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class UnknownInstruction: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class PopOnEmptyStack: public std::exception {
		public:
			const char 				*what(void) const throw();
	};

	class FloatingPointError: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class MissingExitInstruction: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class AssertError: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class OperationOnEmptyStack: public std::exception {
		public:
			const char				*what(void) const throw();
	};

	class ModFloatingPoint: public std::exception {
		public:
			const char 				*what(void) const throw();
	};

	class PrintNonAscii: public std::exception {
		public:
			const char 				*what(void) const throw();
	};

	class PrintOnEmptyStack: public std::exception {
		public:
			const char 				*what(void) const throw();
	};

	class FileDoesNotExist: public std::exception {
		public:
			const char				*what(void) const throw();
	};
};

#endif
