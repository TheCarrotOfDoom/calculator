#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <memory>

class Register;

class Operator
//  Class that describes an operation
{
private:
    std::shared_ptr<Register> registerPtr;
    float value;
    std::string operation;
public:
    Operator(float=0, std::string=0);
    Operator(std::shared_ptr<Register>, std::string);
    ~Operator() = default;
    
    float calculate(float&);

};


#endif //OPERATOR_H