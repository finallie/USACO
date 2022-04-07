/*
ID: aleksil1
TASK: butter
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");

int N, P, C, cow[500], path[800][800];

int main() {
    fin >> N >> P >> C;
    for (int i = 0; i < N; ++i) {
        fin >> cow[i];
        cow[i]--;
    }
    fill_n((int *) path, 800 * 800, 225 * (P - 1));
    for (int i = 0, u, v, d; i < C; ++i) {
        fin >> u >> v >> d;
        path[u - 1][v - 1] = path[v - 1][u - 1] = d;
    }
    for (int i = 0; i < P; ++i) {
        path[i][i] = 0;
    }
    for (int k = 0; k < P; ++k) {
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < P; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += path[i][cow[j]];
        }
        ans = min(ans, sum);
    }
    fout << ans << endl;
    return 0;
}

