/*
ID: aleksil1
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    string s;
    fin >> n >> s;
    vector<ptrdiff_t> v;
    for (auto i = cbegin(s), j = cend(s); i < j;) {
        auto i2 = find_if_not(i + 1, j, [i](auto &&t) { return t == *i; });
        v.push_back(distance(i, i2));
        i = i2;
    }

    ptrdiff_t ans = 0;
    for (decltype(v.size()) size = v.size(), i = 0; i < size; ++i) {
        ans = max(v[i] + v[(i + 1) % size], ans);
    }
    fout << ans << endl;
    return 0;
}

