
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>

#include "Register.h"
#include "Operator.h"

using namespace std;

int main()
{
    string expression{};
    map<string, shared_ptr<Register>> Registers{};

    getline(cin, expression);

    istringstream line{expression};
    string operation{};
    string regName{};
    string value{};


    line >> regName >> operation >> value;
    Registers[regName] = make_shared<Register>(regName);

    if (stof(value))
    {
        Registers[regName]->addOperation(operation, stof(value));
    }
    else
    {
        Registers[value] = make_shared<Register>(value);
        Registers[regName]->addOperation(operation, Registers[regName]);
    }
    
    for (const auto& [key, value] : Registers)
    {
        value->print();
    }
}