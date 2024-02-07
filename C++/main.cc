
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>
#include <algorithm>

#include "Register.h"
#include "Operator.h"

using namespace std;

bool isStof(std::string& value); // Checks if value is convertible to float

int main()
{
    string expression{};
    map<string, shared_ptr<Register>> Registers{};

    while (getline(cin, expression))
    {
        transform(expression.begin(), expression.end(), expression.begin(), ::tolower);

        istringstream line{expression};
        string operation{};
        string regName{};
        string value{};
        string word{};

        line >> word;

        if (word == "quit")
        {
            break;
        }
        else if (word == "print")
        {
            line >> regName;

            cout << Registers[regName]->calculate() << endl;;
        }
        else
        {
            line >> operation >> value;
            regName = word;
            Registers.insert({regName, make_shared<Register>(regName)});

            if (isStof(value))
            {
                Registers[regName]->addOperation(operation, stof(value));
            }
            else
            {
                // 'value' is used as a register name to save memory
                Registers.insert({value, make_shared<Register>(value)});

                Registers[regName]->addOperation(operation, Registers[regName]);
            }
        }
    }
}

bool isStof(std::string& value)
/*  Check if value is convertible to float.
    If convertible return True, else return False  */
{
    std::istringstream iss(value);
    float fValue;
    return (iss >> fValue) && iss.eof();
}