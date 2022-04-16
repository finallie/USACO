/*
ID: aleksil1
TASK: range
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int field[250][250];

int main() {
    ifstream fin("range.in");
    ofstream fout("range.out");

    fin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        fin >> s;
        for (int j = 0; j < N; ++j) {
            field[i][j] = s[j] - '0';
        }
    }

    for (int n = 2; n <= N; ++n) {
        int c = 0;
        for (int i = 0; i + n <= N; ++i) {
            for (int j = 0; j + n <= N; ++j) {
                if ((field[i][j] = (field[i][j] && field[i + 1][j] && field[i][j + 1] && field[i + 1][j + 1])))
                    ++c;
            }
        }
        if (c > 0) {
            fout << n << ' ' << c << endl;
        } else {
            break;
        }
    }

    return 0;
}

