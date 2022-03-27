/*
ID: aleksil1
TASK: hamming
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");
int N, B, D, max_num;
bool dis[256][256];
int path[64];

bool hamming(int a, int b) {
    int n = 0, t = a ^ b;
    while (t) {
        t &= t - 1;
        ++n;
    }
    return n >= D;
}

void dfs(int i, int depth) {
    if (depth == N) {
        for (int j = 0; j < N; ++j) {
            if (j % 10) fout << ' ';
            fout << path[j];
            if (j % 10 == 9 || j == N - 1) fout << endl;
        }
        exit(EXIT_SUCCESS);
    }
    while (i < max_num) {
        bool check = true;
        for (int j = 0; j < depth; ++j) {
            if (!dis[path[j]][i]) {
                check = false;
                break;
            }
        }
        if (check) {
            path[depth] = i;
            dfs(i + 1, depth + 1);
        }
        ++i;
    }
}


int main() {
    fin >> N >> B >> D;
    max_num = 1 << B;
    for (int i = 0; i < max_num; ++i) {
        for (int j = i; j < max_num; ++j) {
            dis[i][j] = hamming(i, j);
        }
    }
    dfs(0, 0);
    return 0;
}

