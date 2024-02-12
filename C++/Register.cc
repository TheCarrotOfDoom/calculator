#include <sstream>

#include "Register.h"
#include "Operation.h"

Register::Register(std::string name)
:operations{}, value{}, name{name}
{}


void Register::addOperation(std::string operation, float value)
//  Add an operation with a float value as operand
{
    operations.push_back(std::make_shared<Operation>(value, operation));
}

void Register::addOperation(std::string operation, std::shared_ptr<Register> registerPtr)
//  Add an operation with a register as operand
{
    operations.push_back(std::make_shared<Operation>(registerPtr, operation));
}

float Register::calculate()
//  Calculate the current value of the given register
{
    value = 0;

    for (auto& op : operations)
    {
            value = op->calculate(value);
    }
    return value;
}

bool Register::isCircularDependent(std::string operand)
// Check if current register is dependent on itself
{
    for (const auto& op : operations)
    {
        if (op->getRegister() != nullptr)
        {
            if (name == operand)
            {
                return true;
            }
            else
            {
                op->getRegister()->isCircularDependent(operand);
            }
        }
    }
    return false;
}