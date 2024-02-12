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
    // VARIABLES //
    std::vector<std::shared_ptr<Operation>> operations;
    float value;
    std::string name;

public:
    // CONSTRUCTORS //
    Register(std::string);
    ~Register() = default;
    
    // FUNCTIONS //
    void addOperation(std::string, float);
    void addOperation(std::string, std::shared_ptr<Register>);

    float calculate();
    bool isCircularDependent(std::string);

};

#endif //REG_H