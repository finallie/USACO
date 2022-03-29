/*
ID: aleksil1
TASK: preface
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");
int N;
string roman = "IVXLCDM";
long long sum[9]{};
int words[9][3]{
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0},
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 0},
        {2, 1, 0},
        {3, 1, 0},
        {1, 0, 1},
};

int main() {
    fin >> N;
    for (int i = 0, base = 1, n = N; n > 0; ++i, base *= 10) {
        for (int j = 0; j < 9 && n > 0; ++j) {
            int t = n / base / 10 * base + min(base, n % (base * 10));
            for (int k = 0; k < 3; ++k) {
                sum[i * 2 + k] += words[j][k] * t;
            }
            n -= base;
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (sum[i])
            fout << roman[i] << ' ' << sum[i] << endl;
    }
    return 0;
}

