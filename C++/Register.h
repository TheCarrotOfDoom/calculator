#ifndef REG_H
#define REG_H

#include <string>
#include <vector>
#include <memory>

class Operator;

class Register
{
private:
    std::string regName;
    std::vector<std::shared_ptr<Operator>> operations;
    float value;

public:
    Register(std::string=0);
    ~Register() = default;
    
    void addOperation(std::string, float);
    void addOperation(std::string, std::shared_ptr<Register>);
    
    float calculate();
    float getValue();

};






#endif //REG_H