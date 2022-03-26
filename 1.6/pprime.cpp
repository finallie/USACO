/*
ID: aleksil1
TASK: pprime
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int a, b;

bool is_prime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int palindrome(int pre) {
    string s = to_string(pre);
    s += string(s.rbegin() + 1, s.rend());
    return stoi(s);
}


int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    fin >> a >> b;
    for (int i: {5, 7, 11}) {
        if (i >= a && i <= b)
            fout << i << '\n';
    }
    for (int i = 10;; ++i) {
        int p = palindrome(i);
        if (p < a) continue;
        if (p > b) break;
        if (is_prime(p))
            fout << p << '\n';
    }
    fout << flush;
    return 0;
}

