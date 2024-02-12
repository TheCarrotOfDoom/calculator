
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Register.h"
#include "Operation.h"

bool isConvertibleToFloat(std::string&); // Checks if value is convertible to float

void calculator(std::istream&); // Calculator function

int main(int argc, char* argv[])
{
    if (argc)
    {
        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            std::cout << ">> Error opening input file." << std::endl;
            return 1;
        }
        calculator(inputFile);
    }
    else
    {
        calculator(std::cin);
    }
}

void calculator(std::istream& input)
{
    std::string expression{};
    std::map<std::string, std::shared_ptr<Register>> Registers{};
    std::vector<std::string> validOperators {"add", "subtract", "multiply"};

    while (getline(input, expression))
    {
        transform(expression.begin(), expression.end(), expression.begin(), ::tolower);

        std::istringstream line{expression};
        std::string operatorStr{};
        std::string registerName{};
        std::string operand{};
        std::string firstWord{};

        line >> firstWord;

        if (firstWord == "print")
        {
            line >> registerName;

            if (Registers.count(registerName))
            // If register exists print
            {
                std::cout << Registers[registerName]->calculate() << std::endl;
            }
            else
            {
                std::cout << ">> Register does not exist." << std::endl;
            }
        }
        else if (firstWord == "quit")
        {
            break;
        }
        else if (isConvertibleToFloat(firstWord))
        {
            std::cout << ">> Invalid register name." << std::endl;
        }
        else
        {
            line >> operatorStr >> operand;
            registerName = firstWord;

            // Check if operationStr is a valid operator
            bool validOperator = std::any_of(validOperators.begin(), validOperators.end(),
                [operatorStr](std::string str){
                    return str == operatorStr;
                });

            if (!validOperator)
            {
                std::cout << ">> Invalid Operator." << std::endl;
                continue;
            }
            else if(registerName == operand || (Registers.count(operand)
                    && Registers[operand]->isDependent(operand)))
            {
                std::cout << ">> Invalid Operand, circular dependency." << std::endl;
                continue;
            }
        
            Registers.insert({registerName, std::make_shared<Register>(registerName)});
        
            if (isConvertibleToFloat(operand))
            {
                // 'operand' is a float
                Registers[registerName]->addOperation(operatorStr, stof(operand));
            }
            else
            {
                //  'operand' is a register, add to Register
                //  map if it doesn't exist
                Registers.insert({operand, std::make_shared<Register>(operand)});
                
                Registers[registerName]->addOperation(operatorStr, Registers[operand]);
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