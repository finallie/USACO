/*
ID: aleksil1
TASK: race3
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N;
int visited[51];
vector<int> street[51];

bool dfs1(int i) {
    visited[i] = 1;
    if (i == N) return false;
    for (const auto &j: street[i]) {
        if (!visited[j]) {
            if (!dfs1(j))
                return false;
        }
    }
    return true;
}

bool dfs2(int i) {
    visited[i] = 2;
    for (const auto &j: street[i]) {
        if (visited[j] == 1) return false;
        if (!visited[j]) {
            if (!dfs2(j))
                return false;
        }
    }
    return true;
}


int main() {
    ifstream fin("race3.in");
    ofstream fout("race3.out");

    string s;
    while (getline(fin, s)) {
        istringstream sin(s);
        int t;
        while (sin >> t) {
            if (t >= 0) {
                street[N].push_back(t);
            } else if (t == -2) {
                ++N;
            }
        }
    }
    --N;

    vector<int> unavoidable_points;
    for (int i = 1; i < N; ++i) {
        memset(visited, 0, sizeof visited);
        visited[i] = 1;
        if (dfs1(0))
            unavoidable_points.push_back(i);
    }
    fout << unavoidable_points.size();
    for (const auto &item: unavoidable_points)
        fout << ' ' << item;
    fout << endl;

    vector<int> splitting_points;
    for (const auto &t: unavoidable_points) {
        memset(visited, 0, sizeof visited);
        visited[t] = 2;
        dfs1(0);
        if (dfs2(t)) splitting_points.push_back(t);
    }
    fout << splitting_points.size();
    for (const auto &item: splitting_points)
        fout << ' ' << item;
    fout << endl;
    return 0;
}

