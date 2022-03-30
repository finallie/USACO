/*
ID: aleksil1
TASK: nocows
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("nocows.in");
ofstream fout("nocows.out");
int N, K;
int dp[200][100];

int solve(int n, int k) {
    if (dp[n][k] >= 0) return dp[n][k];
    if (n < 2 * k - 1 || log2((double) n) >= k) return dp[n][k] = 0;
    dp[n][k] = 0;
    for (int n_left = 1; n_left <= n - 2; n_left += 2) {
        for (int k_left = 1; k_left < k - 1; ++k_left) {
            dp[n][k] += solve(n_left, k_left) * solve(n - n_left - 1, k - 1) * 2;
            dp[n][k] %= 9901;
        }
        dp[n][k] += solve(n_left, k - 1) * solve(n - n_left - 1, k - 1);
        dp[n][k] %= 9901;
    }
    return dp[n][k];
}

int main() {
    fin >> N >> K;
    if (N % 2 == 0) {
        fout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;
    fout << solve(N, K) << endl;
    return 0;
}

