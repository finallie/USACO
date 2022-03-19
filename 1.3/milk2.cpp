/*
ID: aleksil1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    using Pair = pair<int, int>;
    int n;
    fin >> n;
    multiset<Pair> set;
    Pair pair;
    while (n--) {
        fin >> pair.first >> pair.second;
        set.insert(pair);
    }
    pair = *set.begin();
    int a = pair.second - pair.first, b = 0;
    for (const auto &p: set) {
        if (p.first <= pair.second) {
            pair.second = max(pair.second, p.second);
            a = max(a, pair.second - pair.first);
        } else {
            b = max(b, p.first - pair.second);
            pair = p;
        }
    }
    fout << a << ' ' << b << endl;
    return 0;
}

