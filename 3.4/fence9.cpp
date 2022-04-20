/*
ID: aleksil1
TASK: fence9
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, p;

int gcd(int a, int b) {
    while (b) {
        tie(a, b) = make_tuple(b, a % b);
    }
    return a;
}

int main() {
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");

    fin >> n >> m >> p;

    int b = gcd(n, m) - 1 + gcd(abs(p - n), m) - 1 + p - 1 + 3;
    int a = (p * m + 2 - b) / 2;
    fout << a << endl;

    return 0;
}

