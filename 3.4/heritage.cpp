/*
ID: aleksil1
TASK: heritage
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
string s1, s2, s3;
int ind[256];

void post_travel(int i1, int j1, int i2, int j2) {
    if (i1 > j1) return;
    int k = ind[s2[i2]];
    post_travel(i1, k - 1, i2 + 1, i2 + k - i1);
    post_travel(k + 1, j1, i2 + k - i1 + 1, j2);
    s3 += s2[i2];
}

int main() {
    ifstream fin("heritage.in");
    ofstream fout("heritage.out");

    fin >> s1 >> s2;
    for (int i = 0; i < s1.size(); ++i) {
        ind[s1[i]] = i;
    }
    post_travel(0, s1.size() - 1, 0, s2.size() - 1);
    fout << s3 << endl;
    return 0;
}

