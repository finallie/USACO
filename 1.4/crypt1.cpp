/*
ID: aleksil1
TASK: crypt1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int digits[10]{};

bool valid(int n) {
    while (n) {
        if (!digits[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int N, t;
    fin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        fin >> t;
        digits[t] = 1;
        v.push_back(t);
    }
    std::sort(v.begin(), v.end());
    int ans = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            for (int c = 0; c < N; ++c) {
                int abc = v[a] * 100 + v[b] * 10 + v[c];
                for (int d = 0; d < N; ++d) {
                    int p1 = v[d] * abc;
                    if (p1 >= 1000)
                        break;
                    if (valid(p1)) {
                        for (int e = 0; e < N; ++e) {
                            int p2 = v[e] * abc;
                            if (p2 >= 1000) break;
                            if (valid(p2) && valid(p1 * 10 + p2)) {
//                                cout << abc << ' ' << v[d] * 10 + v[e] << ' ' << p1 * 10 + p2 << endl;
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    fout << ans << endl;
    return 0;
}

