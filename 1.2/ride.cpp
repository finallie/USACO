/*
ID: aleksil1
TASK: ride
LANG: C++
PROG: ride
*/
#include <bits/stdc++.h>

using namespace std;

int mode(const string &s) {
    long long t = 1;
    for (const auto &c: s)
        t *= (c - 'A' + 1);
    return (int) (t % 47);
}

int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string comet, group;
    fin >> comet >> group;
    auto ans = mode(comet) == mode(group) ? string("GO") : string("STAY");
    fout << ans << endl;
    return 0;
}

