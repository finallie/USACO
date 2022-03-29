/*
ID: aleksil1
TASK: runround
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("runround.in");
ofstream fout("runround.out");
ll N;

bool is_runround(ll n) {
    bool check[10]{true};
    string s = to_string(n);
    for (const auto c: s) {
        if (check[c - '0']) return false;
        check[c - '0'] = true;
    }
    int t = 0, len = s.size();
    for (int i = 0, j; ;) {
        j = (i + s[i] - '0') % len;
        s[i] = 0;
        i = j;
        ++t;
        if (!s[j]) {
            return t >= len && j == 0;
        }
    }
}

int main() {
    fin >> N;
    do {
        ++N;
    } while (!is_runround(N));
    fout << N << endl;
    return 0;
}

