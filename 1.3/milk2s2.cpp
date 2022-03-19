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
        set.emplace(pair.first, -1);
        set.emplace(pair.second, 1);
    }
    int a = 0, b = 0, sum = 0, lastEnd = set.begin()->first;
    bool noone = true;
    for (const auto &p: set) {
        sum += p.second;
        if (sum == 0) {
            a = max(a, p.first - lastEnd);
            lastEnd = p.first;
            noone = true;
        } else if (noone) {
            b = max(b, p.first - lastEnd);
            lastEnd = p.first;
            noone = false;
        }
    }
    fout << a << ' ' << b << endl;
    return 0;
}

