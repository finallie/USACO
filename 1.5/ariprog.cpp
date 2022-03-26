/*
ID: aleksil1
TASK: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
int bisquares[250 * 250 * 2 + 1]{};
bool is_bisquare[250 * 250 * 2 + 1]{};
int num_bisquares = 0;


int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    fin >> N >> M;
    for (int p = 0; p <= M; ++p) {
        for (int q = 0; q <= M; ++q) {
            int t = p * p + q * q;
            if (!is_bisquare[t]) {
                is_bisquare[t] = true;
                bisquares[num_bisquares++] = t;
            }
        }
    }
    sort(begin(bisquares), begin(bisquares) + num_bisquares);
    const int upper = M * M * 2;

    bool no_answer = true;
    for (int b = 1, max_b = upper/ (N - 1); b <= max_b; ++b) {
        for (int i = 0; bisquares[i]+b*(N-1)<=upper; ++i) {
            int j = 1;
            for(;j<=N-1;++j)
                if(!is_bisquare[bisquares[i]+j*b]) break;
            if (j == N) {
                fout << bisquares[i] << ' ' << b << '\n';
                no_answer = false;
            }
        }
    }
    if (no_answer) fout << "NONE" << endl;
    fout << flush;
    return 0;
}

