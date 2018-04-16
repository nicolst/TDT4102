//
// Created by Nicolai Stølen on 21/03/2018.
//
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <forward_list>
#include <list>

#include "SimpleSet.h"
#include "Person.h"
#include "LinkedList.h"

using namespace std;

void replace(vector<string> &words, string old, string replacement);

void insertOrdered(forward_list<Person>& l, const Person& p);

void listInsertOrdered(list<Person>& l, const Person& p);

template<typename T> void shuffle(T* array, unsigned int length);

template<typename T> T maximum(T& a, T& b);

int main() {
    srand(static_cast<int>(time(nullptr)));

    // Oppgave 1a
    cout << "Oppgave 1a" << endl;
    vector<string> words = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur", "Lorem", "Ipsum", "Lorem", "Ipsum"};

    for (const string &word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    // Oppgave 1b
    cout << "Oppgave 1b" << endl;
    for (auto i = words.rbegin(); i != words.rend(); ++i) {
        cout << *i << " ";
    }
    cout << "\n\n";

    // Oppgave 1c
    cout << "Oppgave 1c" << endl;
    replace(words, "Lorem", "Foo");
    for (const string &word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    // Oppgave 2a
    cout << "Oppgave 2a, set med 0-100" << endl;
    set<int> hundred;
    for (int i = 0; i < 101; ++i) hundred.insert(i);
    for (int i = 0; i < 101; ++i) hundred.insert(i);

    for (const int &i : hundred) cout << i << " ";

    cout << "\n\n";

    // Oppgave 2b
    cout << "Oppgave 2b, set uten 2-gangen" << endl;
    hundred.erase(0);
    for (int i = 2; 2*i < 101; i++) hundred.erase(2*i);

    for (const int &i : hundred) cout << i << " ";

    cout << "\n\n";

    // Oppgave 2c
    cout << "Oppgave 2c, primtall";
    for (int i = 3; i < 51; i++) {
        for (int j = 2; i*j < 101; j++) hundred.erase(i*j);
    }

    for (const int &i : hundred) cout << i << " ";

    cout << "\n\n";

    // Oppgave 2d
    cout << "Oppgave 2d,e" << endl;
    SimpleSet<int> hundred2;
    for (int i = 0; i < 101; ++i) hundred2.insert(i);
    for (int i = 0; i < 101; ++i) hundred2.insert(i);

    cout << "Opprinnelig SimpleSet" << endl << &hundred2;

    hundred2.remove(0);
    for (int i = 2; 2*i < 101; i++) {
        hundred2.remove(2*i);
    }

    cout << "SimpleSet uten 2-gangen" << endl << &hundred2;

    for (int i = 3; i < 51; i++) {
        for (int j = 2; i*j < 101; j++) hundred2.remove(i*j);
    }

    cout << "SimpleSet, primtall" << endl << &hundred2;

    cout << "\n\n";

    // Oppgave 3a
    cout << "Oppgave 3a, shuffle()" << endl;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    shuffle(a, 7); // Resultat, rekkefølgen i a er endret.
    cout << "a[]: ";
    for (int i : a) cout << i << " ";
    cout << endl;
    double b[] = {1.2, 2.2, 3.2, 4.2};
    shuffle(b, 4);
    cout << "b[]: ";
    for (double i : b) cout << i << " ";
    cout << endl;
    string c[] = {"one", "two", "three", "four"};
    shuffle(c, 4); // Resultat, rekkefølgen i c er endret.
    cout << "c[]: ";
    for (string i : c) cout << i << " ";

    cout << "\n\n";

    // Oppgave 3b
    cout << "Oppgave 3b, maximum()" << endl;
    int a1 = 1;
    int b1 = 2;
    int c1 = maximum(a1, b1); // c er nå 2.
    cout << "c1: " << c1 << endl;
    double d = 2.4;
    double e = 3.2;
    double f = maximum(d,e); // f er nå 3.2
    cout << "f: " << f;
    cout << "\n\n";


    // Oppgave 5a
    cout << "Oppgave 5a\n";
    Person p1("Ola", "Nordmann");
    Person p2("Kari", "Olaufsen");
    Person p3("Vilhelm", "Krag");
    Person p4("Jesus", "Kristus");
    Person ps[] = {p1, p2, p3, p4};
    forward_list<Person> forwardPeople;
    for (Person p : ps) insertOrdered(forwardPeople, p);
    for (Person p : forwardPeople) cout << p.getFullName() << "\n";
    cout << "\n\n";

    // Oppgave 5b
    cout << "Oppgave 5b\n";
    list<Person> fwdPeople;
    for (Person p : ps) listInsertOrdered(fwdPeople, p);
    for (Person p : fwdPeople) cout << p.getFullName() << "\n";
    cout << "\n\n";


    // Oppgave 6a
    //LinkedList l6;
    //Node* first = l6.insert(l6.begin(), "Test");




    return 0;
}

// Oppgave 1c
void replace(vector<string> &words, string old, string replacement) {
    for (string &word : words) {
        if (word == old) word = replacement;
    }
}

// Oppgave 3a
template<typename T> void shuffle(T* array, unsigned int length) {
    for (int i = 0; i < length; ++i) {
        int randpos = rand() % length;
        T temp = array[i];
        array[i] = array[randpos];
        array[randpos] = temp;
    }
}

template<typename T> T maximum(T& a, T& b) {
    if (a > b) return a;
    return b;
}

// Oppgave 5a
void insertOrdered(forward_list<Person>& l, const Person& p) {
    if (l.empty() || p < *l.begin()) {
        l.push_front(p);
        return;
    }
    auto prev_it = l.begin();
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (p < *(++it)) {
            l.insert_after(prev_it, p);
            return;
        }
        prev_it = it;
    }
    l.insert_after(prev_it, p);
}


// Oppgave 5b
void listInsertOrdered(list<Person>& l, const Person& p) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (p < *it) {
            l.insert(it, p);
            return;
        }
    }
    l.push_back(p);
}

