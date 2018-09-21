#ifndef ABSTRACT_VM
#define ABSTRACT_VM

# include <iostream>
# include <fstream>
# include "Parser.hpp"
# include "IOperand.hpp"
# include "Exception.hpp"
# include "Factory.hpp"
# include "Operand.hpp"


class AbstractVM {
    public:
        AbstractVM();
        ~AbstractVM();

        void							readFile(std::string filename);
		void							run( void );
        std::list<std::string>			getlist(void);
        Parser  						_tst;
        const Factory					_factory;
        std::list<const IOperand *>		_vassel;
        void							runprog(void);
		void 							push(const std::string &str);
		void 							pop(void);
		void							dump(void) const;
		void 							assert(const std::string &str);
		void 							add(void);
		void 							sub(void);
		void 							mul(void);
		void 							div(void);
		void 							mod(void);
		void							print(void) const;
    private:
        std::list<std::string>			_instructions;
		std::list<std::string>			_type;
		std::list<std::string>			value;
		std::list<std::string>			_allowed;
};

#endif 