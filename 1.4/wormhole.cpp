/*
ID: aleksil1
TASK: wormhole
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int x[13]{}, y[13]{}, next_right[13]{}, pairs[13]{};

bool has_cycle() {
    for (int i = 1; i <= N; ++i) {
        int pos = i;
        for (int j = 0; j < N; ++j) {
            pos = next_right[pairs[pos]];
        }
        if (pos != 0) return true;
    }
    return false;
}

int solve(){
    int i,sum=0;
    for (i = 1; i <= N ; ++i) {
        if (pairs[i] == 0) {
            for (int j = i+1; j <=N ; ++j) {
                if (pairs[j] == 0) {
                    pairs[i] = j;
                    pairs[j] = i;
                    sum += solve();
                    pairs[i] = pairs[j] = 0;
                }
            }
            return sum;
        }
    }
    return has_cycle();
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        fin >> x[i] >> y[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (y[i] == y[j] && x[j] > x[i] && (next_right[i] == 0 || x[j] < x[next_right[i]]))
                next_right[i] = j;
        }
    }
    fout << solve() << endl;
    return 0;
}

