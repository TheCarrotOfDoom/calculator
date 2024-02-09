#include <sstream>

#include "Register.h"
#include "Operator.h"

#include <iostream>

Register::Register(std::string regName)
:regName{regName}, operations{}, value{}
{
}


void Register::addOperation(std::string operation, float value)
{
    operations.push_back(std::make_shared<Operator>(value, operation));
}

void Register::addOperation(std::string operation, std::shared_ptr<Register> regPtr)
{
    operations.push_back(std::make_shared<Operator>(regPtr, operation));
}

std::string Register::getRegister()
{
    return regName;
}

float Register::calculate()
{
    value = 0;

    for (auto& op : operations)
    {
            value = op->calculate(value);
    }
    return value;
}

/*
a add b
b add 10
print a
*/