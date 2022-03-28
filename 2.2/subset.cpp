/*
ID: aleksil1
TASK: subset
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");
int N;
long long dp[38 * 40 / 2 + 1]{1};

int main() {
    fin >> N;
    int sum = N * (N + 1) / 2;
    if (sum % 2) {
        fout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = min(i * (i - 1) / 2, sum / 2 - i); j >= 0; --j) {
            dp[j + i] += dp[j];
        }
    }
    fout << dp[sum / 2] / 2 << endl;
    return 0;
}

