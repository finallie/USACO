/*
ID: aleksil1
TASK: money
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("money.in");
ofstream fout("money.out");
int V, N, v[25];
ll dp[10001]{};


int main() {
    fin >> V >> N;
    for (int i = 0; i < V; ++i) {
        fin >> v[i];
    }
    dp[0] = 1;
    for (int i = 0; i < V; ++i) {
        for (int j = v[i]; j <=N ; ++j) {
            dp[j] += dp[j - v[i]];
        }
    }
    fout << dp[N] << endl;
    return 0;
}

