/*
ID: aleksil1
TASK: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    fin >> N >> M;
    int bisquares[250 * 250 * 2 + 1]{};
    for (int p = 0; p <= M; ++p) {
        for (int q = 0; q <= M; ++q) {
            bisquares[p * p + q * q] = 1;
        }
    }
    bool no_answer = true;
    for (int b = 1, max_b = M * M * 2 / (N - 1); b <= max_b; ++b) {
        for (int a = 0; a + (N - 1) * b <= M * M * 2; ++a) {
            int i;
            for (i = 0; i < N; ++i) {
                if (bisquares[a + i * b] == 0)
                    break;
            }
            if (i == N) {
                fout << a << ' ' << b << '\n';
                no_answer = false;
            }
        }
    }
    if (no_answer) fout << "NONE" << endl;
    fout << flush;
    return 0;
}

