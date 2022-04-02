/*
ID: aleksil1
TASK: inflate
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

int M, N, dp[10001];

int main() {
    fin >> M >> N;
    for (int i = 0, p, m; i < N; ++i) {
        fin >> p >> m;
        for (int j = m; j <= M; ++j) {
            dp[j] = max(dp[j - m] + p, dp[j]);
        }
    }
    fout << dp[M] << endl;
    return 0;
}

