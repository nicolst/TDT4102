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
    // Oppgave 1
    // a)
    vector<string> words = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur", "Lorem", "Ipsum", "Lorem", "Ipsum"};

    for (const string &word : words) {
        cout << word << " ";
    }
    cout << endl;

    // b)
    for (auto i = words.rbegin(); i != words.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // c)
    replace(words, "Lorem", "Foo");
    for (const string &word : words) {
        cout << word << " ";
    }

    set<int> hundred;
    for (int i = 0; i < 101; ++i) hundred.insert(i);
    for (int i = 0; i < 101; ++i) hundred.insert(i);

    hundred.erase(0);
    for (int i = 2; 2*i < *hundred.end(); i++) hundred.erase(2*i);

    for (const int &i : hundred) cout << i << " ";
    cout << endl;

    for (int i = 3; i < 51; i++) {
        for (int j = 2; i*j < *hundred.end(); j++) hundred.erase(i*j);
    }

    for (const int &i : hundred) cout << i << " ";
    cout << endl;






    return 0;
}


void replace(vector<string> &words, string old, string replacement) {
    for (string &word : words) {
        if (word == old) word = replacement;
    }
}