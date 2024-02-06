#include <sstream>

#include "Register.h"
#include "Operator.h"

#include <iostream>

Register::Register(std::string regName)
:regName{regName}, operations{}
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

std::string Register::print()
{
    std::cout << regName << operations.back()->print() << std::endl;
}