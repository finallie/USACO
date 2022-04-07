/*
ID: aleksil1
TASK: ratios
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");


int main() {
    int goal[3], ratio[3][3], total[3];
    fin >> goal[0] >> goal[1] >> goal[2];
    for (auto &i: ratio)
        for (auto &j: i)
            fin >> j;
    for (int sum = 1; sum <= 297; ++sum) {
        for (int i = 0; i <= min(99, sum); ++i) {
            for (int j = 0; j <= min(99, sum - i); ++j) {
                int k = sum - i - j;
                for (int l = 0; l < 3; ++l) {
                    total[l] = ratio[0][l] * i + ratio[1][l] * j + ratio[2][l] * k;
                }
                int t = (total[0] + total[1] + total[2]) / (goal[0] + goal[1] + goal[2]);
                if (total[0] == t * goal[0] && total[1] == t * goal[1] && total[2] == t * goal[2]) {
                    fout << i << ' ' << j << ' ' << k << ' ' << t << endl;
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }
    fout << "NONE" << endl;
    return 0;
}

