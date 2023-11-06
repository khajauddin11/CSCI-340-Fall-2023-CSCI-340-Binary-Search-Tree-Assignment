// binarytree.h
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "node.h"

template <typename T>
class BinaryTree {
protected:
    Node<T> *root;

public:
    BinaryTree() : root(nullptr) {} // Constructor
    virtual ~BinaryTree() {}        // Destructor

    // Define the Inorder traversal that BinarySearchTree will use
    void Inorder(void (*Visit)(const T&)) const {
        _Inorder(root, Visit);
    }

    int getSize() const {
        return _getSize(root);
    }

private:
    void _Inorder(Node<T> *node, void (*Visit)(const T&)) const {
        if (node != nullptr) {
            _Inorder(node->left, Visit);
            Visit(node->data);
            _Inorder(node->right, Visit);
        }
    }

    int _getSize(Node<T> *node) const {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + _getSize(node->left) + _getSize(node->right);
        }
    }
};

#endif // BINARYTREE_H_
