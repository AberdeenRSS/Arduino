#pragma once

#include "allocator.h"

template<class Key, class T>
class BT {

    struct Node {
        Node *left, *right;
        Key key;
        T data;
        Node(Node* l, Node* r, const T& k, const T& d) : left(l), right(r), key(k), data(d) {}
    };

    Node* root;
    Allocator<Node, T> alloc;

public:
    BT() : root(nullptr) {}

    Node* get_root()  {
        return root;
    }

    void insert(const Key& key, const T& data) {
        root = insert_data(root, key, data);
    }

    T find(const Key& key) {
        return find_(root, key);
    }

    void in_order() {
        in_order_(root);
    }

    void show() {
        alloc.show();
    }

private:
    Node* insert_data(Node* ptr,  const Key& key, const T& data) {
        if(!ptr) {
            Node* newNode = alloc.allocate(1);
            alloc.construct(newNode, nullptr, nullptr, key, data);
            return newNode;
        }

        if (key < ptr->key) {
            ptr->left = insert_data(ptr->left, key, data);
        }

        if(ptr->key < key) {
            ptr->right = insert_data(ptr->right, key, data);
        }

        return ptr;
    }

    T find_(Node* ptr, const Key& key) {
        if (ptr->key == key)
            return ptr->data;

        if (key < ptr->key)
            return find_(ptr->left, key);


        if(ptr->key < key)
            return find_(ptr->right, key);

        return nullptr;
    }


    void in_order_(Node* ptr) {
        if(!ptr) return;
        in_order_(ptr->right);

        if(0x50 <= ptr->key) {
            ptr->data->fun(0x00);
            in_order_(ptr->left);
        }
    }
};