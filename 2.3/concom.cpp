/*
ID: aleksil1
TASK: concom
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("concom.in");
ofstream fout("concom.out");
int p[101][101]{}, sum[101][101];
bool controll[101][101]{};


int main() {
    int n, i, j, max_num = 0;
    fin >> n;
    while (n--) {
        fin >> i >> j;
        max_num = max(max(max_num, i), j);
        fin >> p[i][j];
        if (p[i][j] > 50)
            controll[i][j] = true;
    }
    while (true) {
        for (i = 1; i <= max_num; ++i)
            for (j = 1; j <= max_num; ++j)
                sum[i][j] = p[i][j];
        bool updated = false;
        for (i = 1; i <= max_num; ++i)
            for (j = 1; j <= max_num; ++j)
                if (controll[i][j]) {
                    for (int k = 1; k <= max_num; ++k) {
                        if ((sum[i][k] += p[j][k]) > 50 && !controll[i][k]) {
                            controll[i][k] = true;
                            updated = true;
                        }
                    }
                }
        if (!updated) break;
    }
    for (i = 1; i <= max_num; ++i)
        for (j = 1; j <= max_num; ++j)
            if (controll[i][j] && i != j)
                fout << i << ' ' << j << '\n';
    fout << flush;
    return 0;
}

