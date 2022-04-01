/*
ID: aleksil1
TASK: fracdec
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int state[1000001]{};

int main() {
    int N, D;
    fin >> N >> D;
    string s = to_string(N / D) + '.';
    N %= D;
    while (N) {
        N *= 10;
        if (state[N] > 0) {
            s.insert(begin(s) + state[N], '(');
            s += ')';
            break;
        }
        state[N] = s.size();
        s += (char) ('0' + N / D);
        N %= D;
    }
    if (s.back() == '.') s += '0';
    for (int i = 0; i < s.size(); ++i) {
        if (i % 76 == 0 && i > 0)
            fout << '\n';
        fout << s[i];
    }
    fout << endl;
    return 0;
}

