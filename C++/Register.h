#ifndef REG_H
#define REG_H

#include <string>
#include <vector>
#include <memory>

class Operator;

class Register
{
private:
    std::string varName;
    std::vector<std::shared_ptr<Operator>> operations;
public:
    Register(std::string=0);
    ~Register() = default;
};






#endif //REG_H