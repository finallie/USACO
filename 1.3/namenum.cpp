/*
ID: aleksil1
TASK: namenum
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream fdict("dict.txt");
char m[26]{};
string number;

string nameToNumber(const string &name) {
    string s;
    for (auto &c: name)
        s += m[c - 'A'];
    return s;
}

int main() {
    fin >> number;
    for (char c = 'A'; c <= 'P'; ++c)
        m[c - 'A'] = char('2' + (c - 'A') / 3);
    for (char c = 'R'; c <= 'Y'; ++c)
        m[c - 'A'] = char('7' + (c - 'Q') / 3);
    vector<string> v;
    string line;
    while (fdict >> line) {
        if (nameToNumber(line) == number)
            v.push_back(line);
    }
    if (v.empty()) {
        fout << "NONE" << endl;
    } else {
        for (const auto &s: v)
            fout << s << endl;
    }
    return 0;
}

