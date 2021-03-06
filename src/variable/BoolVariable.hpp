#ifndef BOOLVARIABLE_H
#define BOOLVARIABLE_H

#include <functional>
#include <string>
#include "Variable.hpp"
#include <stdexcept>

namespace BCIEvent{
    class BoolVariable : public Variable{
	bool _value = false;
	std::string _name;
	public:

	BoolVariable(std::string name) { _name = name; }

	std::string name() const { return  _name; }
	bool getAsBool() const { return _value; }
	int getAsInt() const { throw std::logic_error("Cannot get value int from variable of type Boolean"); }
	double getAsDouble() const { throw std::logic_error("Cannot get value float from variable of type Boolean"); }

	bool operator==(const Variable& other) { return _value == other.getAsBool(); }
	bool operator==(const bool other) { return _value == other; }
	bool operator==(const int other) { throw std::invalid_argument("Cannot compare bool and int"); }
	bool operator==(const double other) { throw std::invalid_argument("Cannot compare bool and floating point"); }

	void operator=(const Variable& other) { _value = other.getAsBool(); }
	void operator=(const bool other) { _value = other; }
	void operator=(const int other) { throw std::invalid_argument("Cannot assign int to bool"); }
	void operator=(const double other){ throw std::invalid_argument("Cannot assign floating point value to bool"); }

    };
}


#endif
