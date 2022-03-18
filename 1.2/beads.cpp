/*
ID: aleksil1
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    string s;
    fin >> n >> s;
    s += s;
    vector<int> lr(2 * n + 1), lb(2 * n + 1), rr(2 * n + 1), rb(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        if (s[i - 1] == 'r') {
            lr[i] = lr[i - 1] + 1;
            lb[i] = 0;
        } else if (s[i - 1] == 'b') {
            lr[i] = 0;
            lb[i] = lb[i - 1] + 1;
        } else {
            lr[i] = lr[i - 1] + 1;
            lb[i] = lb[i - 1] + 1;
        }
    }
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (s[i] == 'r') {
            rr[i] = rr[i + 1] + 1;
            rb[i] = 0;
        } else if (s[i] == 'b') {
            rr[i] = 0;
            rb[i] = rb[i + 1] + 1;
        } else {
            rr[i] = rr[i + 1] + 1;
            rb[i] = rb[i + 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; ++i) {
        ans = max(ans, max(lr[i], lb[i]) + max(rr[i], rb[i]));
    }
    ans = min(n, ans);
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}

