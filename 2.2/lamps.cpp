/*
ID: aleksil1
TASK: lamps
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
int N, C;
bool dp[64]{}, temp[64];

int get_mask() {
    int mask = 0, t;
    while (true) {
        fin >> t;
        if (t == -1) break;
        mask |= 1 << (5 - (t - 1) % 6);
    }
    return mask;
}

void print_state(int n) {
    string s;
    for (int i = 0; i < 6; ++i) {
        s += (char) ('0' + n % 2);
        n /= 2;
    }
    std::reverse(s.begin(), s.end());
    for (int i = 0; i < N; ++i) {
        fout << s[i % 6];
    }
    fout << '\n';
}

int main() {
    fin >> N >> C;
    dp[63] = true;

    C = C <= 4 ? C : C % 2 == 0 ? 4 : 3;
    while (C--) {
        fill_n(temp, 64, false);
        for (int i = 0; i < 64; ++i) {
            temp[i ^ 0b111111] |= dp[i];
            temp[i ^ 0b101010] |= dp[i];
            temp[i ^ 0b010101] |= dp[i];
            temp[i ^ 0b100100] |= dp[i];
        }
        swap(dp, temp);
    }
    int mask_on = get_mask(), mask_off = get_mask();
    bool found = false;
    for (int i = 0; i < 64; ++i) {
        if (dp[i] && (i & mask_on) == mask_on && (i & mask_off) == 0) {
            found = true;
            print_state(i);
        }
    }
    if (!found) fout << "IMPOSSIBLE" << endl;
    fout << flush;
    return 0;
}

