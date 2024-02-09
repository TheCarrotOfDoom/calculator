
#include "Operator.h"
#include "Register.h"

#include <iostream>

Operator::Operator(float value, std::string operation)
:registerPtr{}, value{value}, operation{operation}
{}

Operator::Operator(std::shared_ptr<Register> registerPtr, std::string operation)
:registerPtr{registerPtr}, value{}, operation{operation}
{
}

float Operator::calculate(float& registerValue)
{
    
    if (registerPtr != nullptr)
    {
        value = registerPtr->calculate();
    }

    if (operation == "add")
    {
        registerValue += value;
    }
    else if (operation == "subtract")
    {
        registerValue -= value;
    }
    else if (operation == "multiply")
    {
        registerValue *= value;
    }
    else
    {
        throw std::logic_error(">> Invalid operation!");
    }

    return registerValue;
}