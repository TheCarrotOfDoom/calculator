#ifndef REG_H
#define REG_H

#include <string>
#include <vector>
#include <memory>

class Operation;

class Register
//  Class that can have operations done to it
{
private:
    std::vector<std::shared_ptr<Operation>> operations;
    float value;
    std::string name;

public:
    Register(std::string);
    ~Register() = default;
    
    void addOperation(std::string, float);
    void addOperation(std::string, std::shared_ptr<Register>);
    
    float calculate();
    bool isDependent(std::string);

};






#endif //REG_H