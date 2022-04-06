/*
ID: aleksil1
TASK: kimbits
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

int N, L;
unsigned int I, dp[32][32];

int main() {
    fin >> N >> L >> I;
    fill_n((unsigned int *) dp, 32 * 32, 1);
    for (int n = 1; n < N; ++n) {
        for (int l = 1; l <= L; ++l) {
            dp[n][l] = dp[n - 1][l] + dp[n - 1][l - 1];
        }
    }
    for (int n = N, l = L; n >= 1; --n) {
        if (I > dp[n - 1][l]) {
            fout << '1';
            I -= dp[n - 1][l];
            l--;
        } else {
            fout << '0';
        }
    }
    fout << endl;
    return 0;
}

