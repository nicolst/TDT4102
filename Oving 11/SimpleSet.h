#ifndef TDT4102_SIMPLESET_H
#define TDT4102_SIMPLESET_H

#include <iostream>



template <typename T> class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet();
        /** Destructor */
        ~SimpleSet();
        /** Insert i into set, return true if the element was inserted, else false **/
        bool insert(T i);
        /** Returns true if i is in the set **/
        bool exists(T i);
        /** Removes i from the set, return true if an element was removed **/
        bool remove(T i);

        template <typename U> friend std::ostream& operator<<(std::ostream& os, SimpleSet<U>* s);
    private:
        /** Dynamic array containing set elements **/
        T* data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
        int find(T i);
        /** Resizes data, superflous elements are dropped. **/
        void resize(int n);
};

template <typename T>
SimpleSet<T>::SimpleSet() {
    data = new T[0];
    currentSize = 0;
    maxSize = SIZE_MAX;
}

template <typename T>
SimpleSet<T>::~SimpleSet() {
    delete[] data;
}

template <typename T>
bool SimpleSet<T>::insert(T i) {
    if (exists(i) or currentSize == maxSize) return false;
    resize(currentSize + 1);
    *(data + currentSize - 1) = i;
}

template <typename T>
bool SimpleSet<T>::exists(T i) {
    return find(i) != -1;
}

template <typename T>
int SimpleSet<T>::find(T i) {
    if (currentSize == 0) return -1;
    int index = -1;
    for (int j = 0; j < currentSize; ++j) {
        if (*(data + j) == i) {
            index = j;
            break;
        }
    }
    return index;
}

template <typename T>
bool SimpleSet<T>::remove(T i) {
    int index = find(i);
    if (index == -1) return false;
    *(data + index) = *(data + currentSize - 1);
    resize(currentSize - 1);
}

template <typename T>
void SimpleSet<T>::resize(int n) {
    int* temp = data;
    currentSize = n;
    data = new T[currentSize];
    for (int i = 0; i < currentSize; ++i) {
        *(data + i) = *(temp + i);
    }
    delete[] temp;
}



template<typename T>
std::ostream &operator<<(std::ostream &os, SimpleSet<T> *s) {
    for (auto p = s->data; p < s->data + s->currentSize; ++p) std::cout << *p << " ";
    std::cout << std::endl;
    return os;
}

#endif // TDT4102_SIMPLESET_H