/*
ID: aleksil1
TASK: stamps
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int K, N, stamp[50];
constexpr int MAX_SUM = 10000 * 200;
int dp[MAX_SUM + 1];

int main() {
    fin >> K >> N;
    for (int i = 0; i < N; ++i) {
        fin >> stamp[i];
    }
    auto mx = *max_element(begin(stamp), end(stamp));
    int max_sum = mx * K;
    fill(begin(dp), end(dp), K + 1);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + stamp[i] <= max_sum; ++j) {
            dp[j + stamp[i]] = min(dp[j + stamp[i]], dp[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_sum && dp[i] <= K; ++i) {
        ++ans;
    }
    fout << ans << endl;
    return 0;
}

