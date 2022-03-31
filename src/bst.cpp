#include "bst.h"

//----------------------------------------------------------------
// Node classes
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
//--------------------------------------------------------------------------
// bst classes

BST::Node*& BST::get_root()
{
    return root;
}

bool BST::add_node(int value)
{
    if (get_root() == nullptr) {
        root = new Node;
        root->value = value;
        root->right = nullptr;
        root->left = nullptr;
        return 1;
    }
    BST::Node* pntr { root };
    while (1) {
        if (value > pntr->value) {
            if (pntr->right == nullptr) {
                pntr->right = new Node;
                pntr = pntr->right;

                pntr->value = value;
                std::cout << *(pntr) << std::endl;
                return 1;
            } else {
                pntr = pntr->right;
            }
        } else {
            if (value == pntr->value)
                return 0;
            if (pntr->left == nullptr) {
                pntr->left = new Node;
                pntr = pntr->left;

                pntr->value = value;
                std::cout << *(pntr) << std::endl;
                return 1;
            } else {
                pntr = pntr->left;
            }
        }
    }
}