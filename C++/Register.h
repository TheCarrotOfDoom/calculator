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

public:
    Register(std::string=0);
    ~Register() = default;
    
    void addOperation(std::string, float);
    void addOperation(std::string, std::shared_ptr<Register>);

    std::string print();


};






#endif //REG_H