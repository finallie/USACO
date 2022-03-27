/*
ID: aleksil1
TASK: frac1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct frac {
    int num;
    int den;

    frac(int num, int den) {
        this->num = num;
        this->den = den;
    }
};

int gcd(int m, int n) {
    while (m) {
        tie(m, n) = make_pair(n % m, m);
    }
    return n;
}

int main() {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    size_t N;
    fin >> N;
    vector<frac> v;
    v.reserve(N * N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (gcd(j, i) == 1)
                v.emplace_back(j, i);
        }
    }
    std::stable_sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.num * b.den < b.num * a.den; });
    for (const auto &f: v)
        fout << f.num << '/' << f.den << '\n';
    fout << flush;
    return 0;
}

