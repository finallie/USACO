/*
ID: aleksil1
TASK: milk
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n, m;
    fin >> n >> m;
    using Pair = pair<int, int>;
    vector<Pair> farmers;
    farmers.reserve(m);
    Pair p;
    for (int i = 0; i < m; ++i) {
        fin >> p.first >> p.second;
        farmers.push_back(p);
    }
    std::sort(farmers.begin(), farmers.end());
    int sum = 0;
    for (const auto &farmer: farmers) {
        auto t = min(n, farmer.second);
        sum += t * farmer.first;
        n -= t;
    }
    fout << sum << endl;
    return 0;
}

