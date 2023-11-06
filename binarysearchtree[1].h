#include "binarytree.h"

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
public:
    void Insert(const T &x) {
        _Insert(this->root, x);
    }

    bool Search(const T &x) const {
        return _Search(this->root, x);
    }

    bool Remove(const T &x) {
        if (Search(x)) {
            _Remove(this->root, x);
            return true;
        } else {
            return false;
        }
    }

private:
    void _Insert(Node<T> *&node, const T &x) {
        if (node == nullptr) {
            node = new Node<T>(x);
        } else if (x < node->data) {
            _Insert(node->left, x);
        } else if (x > node->data) {
            _Insert(node->right, x);
        }
        // If x is equal to node->data, do not insert (no duplicates in BST)
    }

    bool _Search(Node<T> *node, const T &x) const {
        if (node == nullptr) {
            return false;
        } else if (x == node->data) {
            return _Leaf(node);
        } else if (x < node->data) {
            return _Search(node->left, x);
        } else {
            return _Search(node->right, x);
        }
    }

    void _Remove(Node<T> *&node, const T &x) {
        if (node == nullptr) return; // Item not found; do nothing

        if (x < node->data) {
            _Remove(node->left, x);
        } else if (x > node->data) {
            _Remove(node->right, x);
        } else if (_Leaf(node)) { // If it's a leaf
            delete node;
            node = nullptr;
        }
        // If it's not a leaf, do nothing
    }

    // Helper function to find the minimum node (used in case 3)
    Node<T> *_FindMin(Node<T> *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool _Leaf(Node<T> *node) const {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }
};

#endif // BINARYSEARCHTREE_H_
