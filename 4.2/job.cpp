/*
ID: aleksil1
TASK: job
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N, M1, M2, job[1000], mA[30], mB[30], finishA[30], finishB[30];


int main() {
    ifstream fin("job.in");
    ofstream fout("job.out");

    fin >> N >> M1 >> M2;
    for (int i = 0; i < M1; ++i) {
        fin >> mA[i];
    }
    for (int i = 0; i < M2; ++i) {
        fin >> mB[i];
    }

    for (int i = 0; i < N; ++i) {
        int index = 0, endtime = INT_MAX;
        for (int j = 0; j < M1; ++j) {
            if (mA[j] + finishA[j] < endtime) {
                endtime = mA[j] + finishA[j];
                index = j;
            }
        }
        job[i] = finishA[index] = endtime;
    }
    fout << job[N - 1];

    int mx = 0;
    for (int i = N - 1; i >= 0; --i) {
        int index = 0, endtime = INT_MAX;
        for (int j = 0; j < M2; ++j) {
            if (mB[j] + finishB[j] < endtime) {
                endtime = mB[j] + finishB[j];
                index = j;
            }
        }
        job[i] += (finishB[index] = endtime);
        mx = max(mx, job[i]);
    }
    fout << ' ' << mx << endl;
    return 0;
}

