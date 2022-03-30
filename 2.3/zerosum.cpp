/*
ID: aleksil1
TASK: zerosum
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int N;
vector<int> v{1};

void print_line() {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) fout << (v[i] > 0 ? '+' : '-');
        string s = to_string(abs(v[i]));
        fout << s[0];
        for (int j = 1; j < s.size(); ++j) {
            fout << ' ' << s[j];
        }
    }
    fout << '\n';
}

void solve(int n) {
    if (n > N) {
        if (std::accumulate(v.begin(), v.end(), 0) == 0)
            print_line();
        return;
    }

    v.back() = v.back() * 10 + (v.back() > 0 ? n : -n);
    solve(n + 1);
    v.back() /= 10;

    v.push_back(n);
    solve(n + 1);
    v.pop_back();

    v.push_back(-n);
    solve(n + 1);
    v.pop_back();
}

int main() {
    fin >> N;
    solve(2);
    fout << flush;
    return 0;
}

