/*
ID: aleksil1
TASK: milk3
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

bool state[21][21][21]{};
int capacity[3], mount[3]{};

void dfs() {
    if (state[mount[0]][mount[1]][mount[2]]) return;
    state[mount[0]][mount[1]][mount[2]] = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == i) continue;
            int t = min(mount[i], capacity[j] - mount[j]);
            if (t != 0) {
                mount[i] -= t;
                mount[j] += t;
                dfs();
                mount[i] += t;
                mount[j] -= t;
            }
        }
    }
}


int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> capacity[0] >> capacity[1] >> capacity[2];
    mount[2] = capacity[2];
    dfs();
    string ans;
    for (int i = 0; i <= capacity[2]; ++i) {
        if (state[0][capacity[2] - i][i])
            ans += to_string(i) + ' ';
    }
    ans.pop_back();
    fout << ans << endl;
    return 0;
}

