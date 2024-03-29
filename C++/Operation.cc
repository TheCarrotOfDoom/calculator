
#include "Operation.h"
#include "Register.h"

Operation::Operation(float value, std::string operatorStr)
:registerPtr{}, value{value}, operatorStr{operatorStr}
{
}

Operation::Operation(std::shared_ptr<Register> registerPtr, std::string operatorStr)
:registerPtr{registerPtr}, value{}, operatorStr{operatorStr}
{
}

float Operation::calculate(float& registerValue)
// Calculate result of operation
{
    // Check if operand is a register
    if (getRegister() != nullptr)
    {
        value = registerPtr->calculate();
    }

    if (operatorStr == "add")
    {
        registerValue += value;
    }
    else if (operatorStr == "subtract")
    {
        registerValue -= value;
    }
    else if (operatorStr == "multiply")
    {
        registerValue *= value;
    }

    return registerValue;
}

std::shared_ptr<Register> Operation::getRegister()
{
    return registerPtr;
}