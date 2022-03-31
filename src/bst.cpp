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