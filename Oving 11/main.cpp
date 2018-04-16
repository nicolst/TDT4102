//
// Created by Nicolai Stølen on 21/03/2018.
//
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

void replace(vector<string> &words, string old, string replacement);

int main() {
    // Oppgave 1a
    vector<string> words = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur", "Lorem", "Ipsum", "Lorem", "Ipsum"};

    for (const string &word : words) {
        cout << word << " ";
    }
    cout << endl;

    // Oppgave 1b
    for (auto i = words.rbegin(); i != words.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // Oppgave 1c
    replace(words, "Lorem", "Foo");
    for (const string &word : words) {
        cout << word << " ";
    }

    // Oppgave 2a
    set<int> hundred;
    for (int i = 0; i < 101; ++i) hundred.insert(i);
    for (int i = 0; i < 101; ++i) hundred.insert(i);

    cout << *(--(hundred.end())) << endl;

    hundred.erase(0);
    for (int i = 2; 2*i < *(hundred.end()--); i++) hundred.erase(2*i);

    for (const int &i : hundred) cout << i << " ";
    cout << endl;

    for (int i = 3; i < 51; i++) {
        for (int j = 2; i*j < *hundred.end(); j++) hundred.erase(i*j);
    }

    for (const int &i : hundred) cout << i << " ";
    cout << endl;






    return 0;
}

// Oppgave 1c
void replace(vector<string> &words, string old, string replacement) {
    for (string &word : words) {
        if (word == old) word = replacement;
    }
}