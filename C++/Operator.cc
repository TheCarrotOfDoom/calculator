
#include "Operator.h"
#include "Register.h"

#include <iostream>

Operator::Operator(float value, std::string operation)
:reg{}, value{value}, operation{operation}
{
}

Operator::Operator(std::shared_ptr<Register> reg, std::string operation)
:reg{reg}, value{}, operation{operation}
{

}

std::string Operator::print()
{
    return operation + " " + std::to_string(value);
}