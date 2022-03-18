/*
ID: aleksil1
TASK: gift1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    int np;
    fin >> np;
    string s;
    vector<string> names;
    unordered_map<string, int> map;
    while (--np >= 0) {
        fin >> s;
        names.push_back(s);
        map[s] = 0;
    }
    while (fin >> s) {
        int amount, ng;
        fin >> amount >> ng;
        map[s] -= amount;
        if (ng == 0) {
            map[s] += amount;
        } else {
            map[s] += amount % ng;
            int q = amount / ng;
            for (int i = 0; i < ng; ++i) {
                fin >> s;
                map[s] += q;
            }
        }
    }
    ofstream fout("gift1.out");
    for (const auto &name: names)
        fout << name << ' ' << map[name] << endl;
    return 0;
}