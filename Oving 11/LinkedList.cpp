//
// Created by Nicolai Stølen on 16/04/2018.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

ostream& operator<<(ostream& os, const Node& node) {
    os << node.value;
    return os;
}

Node* LinkedList::insert(Node *pos, const std::string &value) {
    Node* prevNode = nullptr;
    for (auto it = begin(); it != end(); ++it) {
        if (it->next == pos) {
            prevNode = &(*it);
            break;
        }
    }
    Node newNode(value, move(prevNode->next));
    prevNode->next = make_unique<Node>(newNode);
}

Node* LinkedList::remove(Node *pos) {
    for (auto it = begin(); it != end(); ++it) {
        if (it->next == pos) {
            it->next = move(it->next->next);
            return it->next.get();
        }
    }
}

Node* LinkedList::find(const std::string &value) {
    for (auto it = begin(); it != end(); ++it) {
        if (it->value == value) return &(*it);
    }
    return head.get();
}

void LinkedList::remove(const string& value) {
    for (auto it = begin(); it != end(); ++it) {
        if (it->next->value == value) {
            it->next = move(it->next->next);
        }
    }
}

ostream& operator<<(ostream& os, const LinkedList& l1) {
    for (auto node : l1) {
        cout << l1 << " ";
    }
    cout << "\n";
}