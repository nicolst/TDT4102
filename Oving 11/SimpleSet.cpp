//
// Created by Nicolai Stølen on 16/04/2018.
//
//
//#include <cstdint>
//#include "SimpleSet.h"
//
//SimpleSet::SimpleSet() {
//    data = new int[0];
//    currentSize = 0;
//    maxSize = SIZE_MAX;
//}
//
//SimpleSet::~SimpleSet() {
//    delete[] data;
//}
//
//bool SimpleSet::insert(int i) {
//    if (exists(i) or currentSize == maxSize) return false;
//    resize(currentSize + 1);
//    *(data + currentSize - 1) = i;
//}
//
//bool SimpleSet::exists(int i) {
//    return find(i) != -1;
//}
//
//int SimpleSet::find(int i) {
//    if (currentSize == 0) return -1;
//    int index = -1;
//    for (int j = 0; j < currentSize; ++j) {
//        if (*(data + j) == i) {
//            index = j;
//            break;
//        }
//    }
//    return index;
//}
//
//bool SimpleSet::remove(int i) {
//    int index = find(i);
//    if (index == -1) return false;
//    *(data + index) = *(data + currentSize - 1);
//    resize(currentSize - 1);
//}
//
//void SimpleSet::resize(int n) {
//    int* temp = data;
//    currentSize = n;
//    data = new int[currentSize];
//    for (int i = 0; i < currentSize; ++i) {
//        *(data + i) = *(temp + i);
//    }
//    delete[] temp;
//}
//
//std::ostream& operator<<(std::ostream &os, SimpleSet* s) {
//    for (auto p = s->data; p < s->data + s->currentSize; ++p) std::cout << *p << " ";
//    std::cout << std::endl;
//    return os;
//}