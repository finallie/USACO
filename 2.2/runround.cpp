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

ll next_runround(ll n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    std::reverse(v.begin(), v.end());

    while (true) {
        bool found = false;
        for (int i = 0; i < v.size(); ++i) {
            int j = (i + v[i]) % v.size();
            if (v[i] == v[j]) {
                found = true;
                int index = max(i, j);
                while (v[index] == 9 && index >= 0)
                    --index;
                if (index == -1) {
                    index = 0;
                    v.insert(begin(v), 0);
                }
                v[index]++;
                fill(begin(v) + index + 1, end(v), 1);
                break;
            }
        }
        if (!found) break;
    }

    for (ll i: v)
        n = n * 10 + i;
    return n;
}

int main() {
    fin >> N;
    fout << next_runround(N + 1) << endl;
    return 0;
}

