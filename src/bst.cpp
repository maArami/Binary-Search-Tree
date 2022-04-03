#include "bst.h"

//----------------------------------------------------------------
// Node classes
BST::Node* M {};
BST::Node::Node(int _value, Node* _left, Node* _right)
    : value { _value }
    , left { _left }
    , right { _right }

{
}

BST::Node::Node()
    : BST::Node::Node(0, nullptr, nullptr)
{
}

BST::Node::Node(const Node& node)
    : value { node.value }
    , right { new Node }
    , left { new Node }
{

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
        M = root;
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

                return 1;
            } else {
                pntr = pntr->left;
            }
        }
    }
}

size_t BST::length()
{
    int cnt {};
    if (root == nullptr)
        return 0;
    BST bst {};
    bst.root = root->left;
    cnt += bst.length();
    bst.root = root->right;
    cnt += bst.length();
    return cnt + 1;
}

BST::Node** BST::find_node(int value)
{
    if (root == nullptr)
        return nullptr;
    std::queue<Node**> vec;
    vec.push(&root);
    Node** pntr = vec.back();
    while (1) {

        if (value == (*pntr)->value) {

            return pntr;
        }
        if (value > (*pntr)->value) {
            if ((*pntr)->right == nullptr)
                return nullptr;
            vec.push(&(*pntr)->right);
            vec.pop();
            pntr = vec.back();

        } else if (value < (*pntr)->value) {
            if ((*pntr)->left == nullptr) {
                return nullptr;
            }
            vec.push(&(*pntr)->left);
            vec.pop();
            pntr = vec.back();
        }
    }
}

BST::Node** BST::find_parrent(int value)
{
    if (root == nullptr)
        return nullptr;

    std::queue<Node**> vec;
    vec.push(&root);
    Node** pntr = vec.back();
    while (1) {

        if (value == (*pntr)->left->value || value == (*pntr)->right->value) {
            return pntr;
        }
        if (value > (*pntr)->value) {
            if ((*pntr)->right == nullptr)
                return nullptr;
            vec.push(&(*pntr)->right);
            vec.pop();
            pntr = vec.back();

        } else if (value < (*pntr)->value) {
            if ((*pntr)->left == nullptr) {
                return nullptr;
            }
            vec.push(&(*pntr)->left);
            vec.pop();
            pntr = vec.back();
        }
    }
}

BST::Node** BST::find_successor(int value)
{
    if (root == nullptr)
        return nullptr;
    std::queue<Node**> vec;
    vec.push(find_node(value));
    Node** pntr = vec.back();
    if ((*pntr)->left == nullptr)
        return pntr;
    vec.push(&(*pntr)->left);
    vec.pop();
    pntr = vec.back();
    while (1) {
        if ((*pntr)->right == nullptr)
            return pntr;
        vec.push(&(*pntr)->right);
        vec.pop();
        pntr = vec.back();
    }
}
bool BST::delete_node(int value)
{

    if (root == nullptr)
        return 0;
    if (find_node(value) == nullptr)
        return 0;
    Node** pntr = find_node(value);

    if ((*pntr)->left == nullptr && (*pntr)->right == nullptr) {
        delete (*pntr);
        (*pntr) = nullptr;
        return 1;
    } else if ((*pntr)->left == nullptr) {
        (*pntr) = (*pntr)->right;
        return 1;
    } else if ((*pntr)->right == nullptr) {
        (*pntr) = (*pntr)->left;
        return 1;
    } else {
        Node** pntr2 = find_successor(value);
        (*pntr) = (*pntr2);
        delete (*pntr2);
        (*pntr2) = nullptr;
        return 1;
    }
}