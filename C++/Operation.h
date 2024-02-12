#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <memory>

class Register;

class Operation
//  Class that describes an operation
{
private:
    std::shared_ptr<Register> registerPtr;
    float value;
    std::string operatorStr;
public:
    Operation(float=0, std::string=0);
    Operation(std::shared_ptr<Register>, std::string);
    ~Operation() = default;
    
    float calculate(float&);
    bool isConst();
    std::shared_ptr<Register> getRegister();
};

#endif //OPERATOR_H