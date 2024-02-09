
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

float Operator::calculate(float& regValue)
{
    
    if (reg != nullptr)
    {
        value = reg->calculate();
    }

    if (operation == "add")
    {
        regValue += value;
    }
    else if (operation == "subtract")
    {
        regValue -= value;
    }
    else if (operation == "multiply")
    {
        regValue *= value;
    }

    return regValue;
}