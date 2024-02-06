#ifndef NODE_H
#define NODE_H

#include <memory>

class Node
{
protected:
    std::shared_ptr<Node> node;
public:
    Node() = default;
    ~Node() = default;
};

#endif //NODE_H