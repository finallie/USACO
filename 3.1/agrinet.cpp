/*
ID: aleksil1
TASK: agrinet
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int N, graph[100][100], joined[100], dis[100], sum;

int main() {
    fin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 0; i < N; ++i) {
        int mn = INT_MAX, next_v = -1;
        for (int j = 0; j < N; ++j) {
            if (joined[j]) continue;
            if (dis[j] < mn) {
                mn = dis[j];
                next_v = j;
            }
        }
        sum += mn;
        joined[next_v] = 1;
        for (int j = 0; j < N; ++j) {
            dis[j] = min(dis[j], graph[next_v][j]);
        }
    }
    fout << sum << endl;
    return 0;
}

