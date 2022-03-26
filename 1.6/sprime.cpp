/*
ID: aleksil1
TASK: sprime
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;

bool is_prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    fin >> N;
    deque<int> q{2, 3, 5, 7};
    for (int i = 2; i <= N; ++i) {
        for (size_t j = 0, len = q.size(); j < len; ++j) {
            for (int k: {1, 3, 7, 9}) {
                int p = q.front() * 10 + k;
                if (is_prime(p))
                    q.push_back(p);
            }
            q.pop_front();
        }
    }
    for (const auto &p: q)
        fout << p << '\n';
    fout << flush;
    return 0;
}

