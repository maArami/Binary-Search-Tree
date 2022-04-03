#ifndef BST_H
#define BST_H

#include <compare>
#include <iostream>
#include <queue>

class BST {
public:
    class Node {
    public:
        Node(int _value, Node* _left, Node* _right);
        Node();
        Node(const Node& node);

        std::partial_ordering operator<=>(const int& _value) { return value <=> _value; }
        bool operator==(const int& _value) { return value == _value; }

        int value;
        Node* left;
        Node* right;
    };

    Node*& get_root();
    // void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

private:
    Node* root;
};

std::ostream& operator<<(std::ostream& os, const BST::Node& node);

#endif // BST_H