#pragma once


template<class T>
class Wrapper {
public:
    Wrapper() : nextCall(0), ptr(nullptr) {}

    Wrapper(unsigned long time, T data)
        : nextCall(time),
          ptr(data) {}

    T get_val() const {
        return ptr;
    }

    bool operator< (const Wrapper& obj) const {
        return  nextCall < obj.nextCall;
    }

    T show() const {
        return ptr;
    }

    void remove() {
        nextCall = 0;
        ptr = nullptr;
    }

    void setTime(unsigned long nextUpdate) {
        nextCall = nextUpdate;
    }

    unsigned long getTime() const {
        return nextCall;
    }

    void setPtr(T newPtr) {
        ptr = newPtr;
    }

private:
    unsigned long nextCall;
    T ptr;
};


class Interface;

template<class T>
class Heap {
public:
    Heap() : size(0) {}

    void insert(unsigned long nextUpdate, Interface* data) {
        arr[size].setTime(nextUpdate);
        arr[size].setPtr(data);

        _insert((size - 1) / 2, size);
        ++size;
    }

    void pop() {
        if(!size) return;

        --size;
        swap(0, size);
        arr[size].remove();

        _pop(0);
    }

    T top() const {
        return arr[0];
    }

    int get_size() const {
        return size;
    }

    bool empty() const {
        return !size;
    }
private:
    const int capacity = 5;
    int size;
    T arr[5];

private:
    void _insert(int s, int target) {
        if(!target) return;
        if (arr[target] < arr[s]) {
            swap(target, s);

            _insert((s - 1) / 2, s);
        }
    }

    void _pop(uint8_t parent) {
        uint8_t smallest = parent;
        uint8_t l = 2 * parent + 1;
        uint8_t r = 2 * parent + 2;

        if(l < size && arr[l] < arr[smallest])
            smallest = l;


        if(r < size && arr[r] < arr[smallest])
            smallest = r;

        if(smallest != parent) {
            swap(parent, smallest);

            _pop(smallest);
        }
    }

    void swap(uint8_t firstIndex, uint8_t secondIndex) {
        T t = arr[firstIndex];
        arr[firstIndex] = arr[secondIndex];
        arr[secondIndex] = t;
    }
};