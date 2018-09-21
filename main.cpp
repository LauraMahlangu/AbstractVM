# include <iostream>
# include <fstream>
# include "AbstractVM.hpp"
# include "Parser.hpp"
# include "Exception.hpp"
# include "Operand.hpp"

int main(int argc, char ** argv) {
	try{
		AbstractVM	_mainProg;
		if (argc == 2) {
			std::string file(argv[1]);
			_mainProg.readFile(file);
			_mainProg.run();
			_mainProg.runprog();
		} else
			throw Exception::FileDoesNotExist();
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}