/*
ID: aleksil1
TASK: rockers
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int dp[21][21];

int main() {
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");

    fin >> N >> T >> M;
    for (int n; fin >> n;) {
        if (n > T) continue;
        for (int i = M; i >= 1; --i) {
            for (int j = T; j >= 0; --j) {
                if (j >= n) {
                    dp[i][j] = max(dp[i][j], dp[i][j - n] + 1);
                } else if (i > 1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][T - n] + 1);
                }
            }
        }
    }
    fout << dp[M][T] << endl;
    return 0;
}

