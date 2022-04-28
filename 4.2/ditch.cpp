/*
ID: aleksil1
TASK: ditch
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
    prefix[1] = -1;
    q.clear();
    q.emplace_back(1, INT_MAX);
    while (!q.empty()) {
        int s, e, c;
        tie(s, c) = q.front();
        if (s == M) {
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
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");

    fin >> N >> M;
    int t = M;
    for (int i = 0, s, e, c; i < N; ++i) {
        fin >> s >> e >> c;
        if (graph[e][s] == 0) {
            graph[s][e] = c;
        } else {
            ++t;
            graph[e][t] = graph[e][s];
            graph[t][e] = c;
            graph[s][t] = c;
            graph[t][s] = graph[e][s];
            graph[e].erase(s);
            graph[s].erase(e);
        }
    }

    while (find_path()) {

    }

    fout << flow << endl;
    return 0;
}

