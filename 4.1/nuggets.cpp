/*
ID: aleksil1
TASK: nuggets
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

using window = bitset<256>;
window mask, cur;

int gcd(int a, int b) {
    while (b) {
        tie(a, b) = make_tuple(b, a % b);
    }
    return a;
}


int main() {
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");

    int N, t, mn, ans = 0, _gcd;
    fin >> N;
    fin >> t;
    mask[t - 1] = true;
    mn = t;
    _gcd = t;
    while (fin >> t) {
        mask[t - 1] = true;
        mn = min(mn, t);
        _gcd = gcd(t, _gcd);
    }
    if (_gcd > 1) {
        fout << 0 << endl;
        return 0;
    }
    cur = mask;
    for (int acc = 0, i = 1;; ++i) {
        if (cur[0]) {
            if (++acc == mn) {
                fout << ans << endl;
                return 0;
            }
            cur >>= 1;
            cur |= mask;
        } else {
            acc = 0;
            cur >>= 1;
            ans = i;
        }
    }
    return 0;
}

