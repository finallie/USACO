/*
ID: aleksil1
TASK: holstein
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

size_t V, G;
int v[25], g[15][25];
int cur[15], path[15], mn = 15;

void dfs(int i, int depth) {
    bool yes = true;
    for (int j = 0; j < V; ++j)
        if (v[j] > 0) {
            yes = false;
            break;
        }
    if (yes) {
        mn = depth;
        copy(cur, cur + depth, path);
        return;
    }
    while (i < G && depth + 1 < mn) {
        for (int j = 0; j < V; ++j) {
            v[j] -= g[i][j];
        }
        cur[depth] = i;
        dfs(i + 1, depth + 1);
        for (int j = 0; j < V; ++j) {
            v[j] += g[i][j];
        }
        ++i;
    }

}

int main() {
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin >> V;
    for (int i = 0; i < V; ++i) {
        fin >> v[i];
    }
    fin >> G;
    for (int i = 0; i < G; ++i) {
        for (int j = 0; j < V; ++j) {
            fin >> g[i][j];
        }
    }
    dfs(0, 0);
    fout << mn;
    for (int i = 0; i < mn; ++i) {
        fout << ' ' << path[i] + 1;
    }
    fout << endl;
    return 0;
}

