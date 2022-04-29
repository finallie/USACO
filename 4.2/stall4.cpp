/*
ID: aleksil1
TASK: stall4
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N, M;
ll flow;
unordered_map<int, unordered_map<int, int>> graph;
deque<pair<int, int>> q;

bool find_path() {
    int prefix[500]{};
    prefix[0] = -1;
    q.clear();
    q.emplace_back(0, INT_MAX);
    while (!q.empty()) {
        int s, e, c;
        tie(s, c) = q.front();
        if (s == 401) {
            flow += c;
            while (prefix[s] != -1) {
                graph[prefix[s]][s] -= c;
                graph[s][prefix[s]] += c;
                s = prefix[s];
            }
            return true;
        }
        q.pop_front();
        for (const auto &edge: graph[s]) {
            if (edge.second != 0 && prefix[edge.first] == 0) {
                q.emplace_back(edge.first, min(edge.second, c));
                prefix[edge.first] = s;
            }

        }
    }
    return false;
}

int main() {
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");

    fin >> N >> M;
    for (int i = 1, j, k; i <= N; ++i) {
        fin >> j;
        while (j--) {
            fin >> k;
            graph[i][k + 200] = 1;
        }
    }
    for (int i = 1; i <= N; ++i) {
        graph[0][i] = 1;
    }
    for (int i = 1; i <= M; ++i) {
        graph[i + 200][401] = 1;
    }

    while (find_path()) {

    }

    fout << flow << endl;
    return 0;
}

