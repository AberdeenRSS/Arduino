#pragma once
#include "Arduino.h"

namespace {
    const int n = 40;

    void* array() {
        static char arr[n];
        return arr;
    }
};

template<class T, class Data>
struct Allocator {
    Allocator() : shift(0), arr(array()) {}

    T* allocate(int n) {
        return static_cast<T*>(arr) + shift++;
    }

    void construct(T* obj, T* left, T* right, int key, const Data& data) {
        obj->left = left;
        obj->right = right;
        obj->data = data;
        obj->key = key;
    }

    void show() {
        /*
        char* ptr = static_cast<char*>(arr);
        for(uint16_t i = 0; i < 256; ++i) {
            Serial.print("I (");
            Serial.print(i);
            Serial.print(") = ");
            Serial.println(ptr[i]);
        }*/
    }

private:
    uint8_t shift;
    void* arr;
};