#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <sstream>

# include "Factory.hpp"
# include "IOperand.hpp"
# include "Exception.hpp"

template <typename T>
class Operand : public IOperand {
  
  private:
  T                   _value;
  const eOperandType  _type;
  Factory             _create;

public:
  Operand(void) : _type(Int8), _value(0)
  {
    return ;
  }

  Operand(const eOperandType type, const T value) : _value(value), _type(type)
  {
    return ;
  }

  ~Operand(void)
  {
    return ;
  }

  Operand &operator=(const Operand &rhs)
  {
    return (*new Operand(rhs));
  }

  int getPrecision(void) const
  {
    return (_type);
  }

  eOperandType getType(void) const
  {
    return (this->_type);
  }

  std::string const & toString(void) const
  {
    std::stringstream ss;
	  if (this->_type == Int8)
		   ss << static_cast<int32_t>(this->_value);
	  else
    	 ss << this->_value;
    return (*new std::string(ss.str()));
  }

  T getValue(void) const
  {
    return (this->_value);
  }

  IOperand const	* operator+(IOperand const &rhs) const
  {
    eOperandType  type;
    int           number = 0;
    double        digits = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() + _value));
    } else {
      type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        number = std::stoi(rhs.toString()) + _value;
        return (_create.createOperand(type, std::to_string(number)));
      }
      if (type == Float || type == Double) {
        digits = std::stod(rhs.toString()) + _value;
        return (_create.createOperand(type, std::to_string(digits)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator-(IOperand const &rhs) const
  {
    eOperandType  type;
    int           number = 0;
    double        digits = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() - _value));
    } else {
      type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        number = std::stoi(rhs.toString()) - _value;
        return (_create.createOperand(type, std::to_string(number)));
      }
      if (type == Float || type == Double) {
        digits = std::stod(rhs.toString()) - _value;
        return (_create.createOperand(type, std::to_string(digits)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator*(IOperand const &rhs) const
  {
    eOperandType  type;
    int           number = 0;
    double        digits = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() * _value));
    } else {
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        number = std::stoi(rhs.toString()) * _value;
        return (_create.createOperand(type, std::to_string(number)));
      }
      if (type == Float || type == Double) {
        digits = std::stod(rhs.toString()) * _value;
        return (_create.createOperand(type, std::to_string(digits)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator/(IOperand const &rhs) const
  {
    eOperandType  type;
    int           number = 0;
    double        digits = 0;

    if (_type == rhs.getPrecision()) {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() / _value));
    } else {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        number = std::stoi(rhs.toString()) / _value;
        return (_create.createOperand(type, std::to_string(number)));
      }
      if (type == Float || type == Double) {
        digits = std::stod(rhs.toString()) / _value;
        return (_create.createOperand(type, std::to_string(digits)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator%(IOperand const &rhs) const
  {
    eOperandType  type;
    int           number = 0;
    const Operand<T> *getV = NULL;

    if (_type == rhs.getPrecision()) {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      getV = static_cast<const Operand<T>*>(&rhs);
      return (new Operand<T>(_type, static_cast<long int>(getV->getValue()) % static_cast<long int>(_value)));
    } else {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        number = static_cast<long int>(std::stoi(rhs.toString())) % static_cast<long int>(_value);
        return (_create.createOperand(type, std::to_string(number)));
      }
      if (type == Float || type == Double) {
        throw Exception::ModFloatingPoint();
      }
    }
    return (NULL);
  }


};

#endif
