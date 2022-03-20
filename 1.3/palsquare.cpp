/*
ID: aleksil1
TASK: palsquare
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

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int base;
    fin >> base;
    for (int i = 1; i <= 300; ++i) {
        auto s = int2string(i * i, base);
        if (isPal(s))
            fout << int2string(i, base) << ' ' << s << endl;
    }
    return 0;
}

