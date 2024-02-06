
#include "Operator.h"
#include "Register.h"

using namespace std;

Operator::Operator(float value, string operation)
:value{value}, operation{operation}
{
}

Operator::Operator(std::shared_ptr<Register> reg, string operation)
:reg{}, operation{operation}
{

}