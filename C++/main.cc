
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>
#include <algorithm>

#include "Register.h"
#include "Operator.h"

using namespace std;

bool isConvertibleToFloat(std::string& value); // Checks if value is convertible to float

int main()
{
    string expression{};
    map<string, shared_ptr<Register>> Registers{};

    while (getline(cin, expression))
    {
        transform(expression.begin(), expression.end(), expression.begin(), ::tolower);

        istringstream line{expression};
        string operation{};
        string registerName{};
        string operand{};
        string input{};

        line >> input;

        if (input == "print")
        {
            line >> registerName;

            if (Registers.count(registerName) != 0)
            // If register exists print
            {
                cout << Registers[registerName]->calculate() << endl;
            }
            else
            {
                std::cout << ">> Register does not exist." << std::endl;
            }
        }
        else if (input == "quit")
        {
            break;
        }
        else if (isConvertibleToFloat(input))
        {
            std::cout << ">> Invalid register name." << std::endl;
        }
        else
        {
            line >> operation >> operand;

            registerName = input;

            Registers.insert({registerName, make_shared<Register>()});
            try
            {
                if (isConvertibleToFloat(operand))
                {
                    // 'operand' is a float
                    Registers[registerName]->addOperation(operation, stof(operand));
                }
                else
                {
                    //  'operand' is a register, add to Register
                    //  map if it doesn't exist
                    Registers.insert({operand, make_shared<Register>()});
                    
                    Registers[registerName]->addOperation(operation, Registers[operand]);
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
    }
}

bool isConvertibleToFloat(std::string& value)
//  Check if value is convertible to float.
//  If convertible return True, else return False
{
    std::istringstream iss(value);
    float fValue;
    return (iss >> fValue) && iss.eof();
}