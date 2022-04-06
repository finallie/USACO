/*
ID: aleksil1
TASK: spin
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");

int wheel[5][360], speed[5];

int main() {
    int n, start, extent;
    for (int i = 0; i < 5; ++i) {
        fin >> speed[i] >> n;
        for (int j = 0; j < n; ++j) {
            fin >> start >> extent;
            for (int k = start; k <= start + extent; ++k) {
                wheel[i][k % 360] = 1;
            }
        }
    }
    for (int t = 0; t < 360; ++t) {
        for (int i = 0; i < 360; ++i) {
            if (wheel[0][i] + wheel[1][i] + wheel[2][i] + wheel[3][i] + wheel[4][i] == 5) {
                fout << t << endl;
                exit(EXIT_SUCCESS);
            }
        }
        for (int i = 0; i < 5; ++i) {
            rotate(begin(wheel[i]), end(wheel[i]) - speed[i], end(wheel[i]));
        }
    }
    fout << "none" << endl;
    return 0;
}

