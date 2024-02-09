#ifndef REG_H
#define REG_H

#include <string>
#include <vector>
#include <memory>

class Operator;

class Register
//  Class that can have operations done to it
{
private:
    std::vector<std::shared_ptr<Operator>> operations;
    float value;

public:
    Register();
    ~Register() = default;
    
    void addOperation(std::string, float);
    void addOperation(std::string, std::shared_ptr<Register>);
    
    float calculate();

};






#endif //REG_H