#include "bst.h"

BST::Node::Node(int _value, Node* _left, Node* _right)
    : value { _value }
    , left { _left }
    , right { _right }

{
    std::cout << "Node Main constructor" << std::endl;
}

BST::Node::Node()
    : BST::Node::Node(0, nullptr, nullptr)
{
    std::cout << "Defaulte cosntructor" << std::endl;
}

BST::Node::Node(const Node& node)
    : value { node.value }
    , right { new Node }
    , left { new Node }
{
    std::cout << "Copy cosntructor" << std::endl;
    right = node.right;
    left = node.left;
}

std::ostream& operator<<(std::ostream& os, const BST::Node& node)
{
    os << "adress of node: " << &node << std::endl;
    os << "value of node: " << node.value << std::endl;
    os << "adress of left: " << node.left << std::endl;
    os << "adress of right: " << node.right << std::endl;
    return os;
}