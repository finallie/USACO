/*
ID: aleksil1
TASK: race3
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N;
bool unavoidable[51], visited[51], p1[51];
vector<int> street[51];

void dfs(int i) {
    if (i == N) {
        for (int j = 0; j <= N; ++j) {
            unavoidable[j] = unavoidable[j] && visited[j];
        }
    }
    for (int j: street[i]) {
        if (!visited[j]) {
            visited[j] = true;
            dfs(j);
            visited[j] = false;
        }
    }
}

void dfs_p1(int i, int target) {
    p1[i] = true;
    if (i == target)
        return;
    for (int j: street[i]) {
        if (!visited[j]) {
            visited[j] = true;
            dfs_p1(j, target);
            visited[j] = false;
        }
    }
}

bool dfs_p2(int i) {
    if (p1[i]) return false;
    for (int j: street[i]) {
        if (!visited[j]) {
            visited[j] = true;
            if (!dfs_p2(j)) {
                visited[j] = false;
                return false;
            }
            visited[j] = false;
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

    for (int i = 0; i <= N; ++i) {
        unavoidable[i] = true;
    }
//    visited[0] = true;
    dfs(0);

    vector<int> unavoidable_points;
    for (int i = 1; i < N; ++i) {
        if (unavoidable[i])
            unavoidable_points.push_back(i);
    }
    fout << unavoidable_points.size();
    for (const auto &item: unavoidable_points)
        fout << ' ' << item;
    fout << endl;

    vector<int> splitting_points;
    for (const auto &t: unavoidable_points) {
        fill(begin(p1), end(p1), false);
        dfs_p1(0, t);
        p1[t] = false;
        if (dfs_p2(t))
            splitting_points.push_back(t);
    }
    fout << splitting_points.size();
    for (const auto &item: splitting_points)
        fout << ' ' << item;
    fout << endl;
    return 0;
}

