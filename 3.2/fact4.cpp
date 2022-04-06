/*
ID: aleksil1
TASK: fact4
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

int main() {
    int N;
    fin >> N;
    int c5 = 0;
    for (int i = 5; i < N; i *= 5) {
        c5 += N / i;
    }
    int c2 = c5, ans = 1;
    for (int i = 1; i <= N; ++i) {
        ans *= i;
        while (c2 && ans % 2 == 0) {
            ans /= 2;
            c2--;
        }
        while (c5 && ans % 5 == 0) {
            ans /= 5;
            c5--;
        }
        ans %= 10;
    }
    fout << ans << endl;
    return 0;
}

