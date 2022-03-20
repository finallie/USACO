/*
ID: aleksil1
TASK: dualpal
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

bool isPal(const string &s) {
    for (auto i = s.cbegin(), j = s.cend() - 1; i <= j; ++i, --j)
        if (*i != *j)
            return false;
    return true;
}

string int2string(int n, int r) {
    const static string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    while (n) {
        s += base[n % r];
        n /= r;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

bool isDualpal(int n) {
    for (int i = 2, count = 0; i <= 10; ++i) {
        if (isPal(int2string(n, i)))
            if (++count >= 2)
                return true;
    }
    return false;
}


int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n, s;
    fin >> n >> s;
    for (int i = s + 1; n > 0; ++i) {
        if (isDualpal(i)) {
            fout << i << endl;
            n--;
        }
    }
    return 0;
}

