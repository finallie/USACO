/*
ID: aleksil1
TASK: ttwo
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
char m[12][12];
constexpr int state_count = 10 * 10 * 4 * 10 * 10 * 4;
int dir[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

void step(int &i, int &j, int &d) {
    if (m[i + dir[d][0]][j + dir[d][1]] == '*') {
        d = (d + 1) % 4;
    } else {
        i += dir[d][0];
        j += dir[d][1];
    }
}

int main() {
    fill_n((char *) m, 12 * 12, '*');
    int ci, cj, fi, fj, cd = 0, fd = 0;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            fin >> m[i][j];
            if (m[i][j] == 'C') {
                ci = i;
                cj = j;
            } else if (m[i][j] == 'F') {
                fi = i;
                fj = j;
            }
        }
    }
    for (int i = 1; i <= state_count; ++i) {
        step(ci, cj, cd);
        step(fi, fj, fd);
        if (ci == fi && cj == fj) {
            fout << i << endl;
            exit(EXIT_SUCCESS);
        }
    }
    fout << 0 << endl;
    return 0;
}

