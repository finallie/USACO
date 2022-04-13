/*
ID: aleksil1
TASK: butter
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int N, P, C, cow[500], dis[801][801];
constexpr int INF = INT_MAX / 2;

int main() {
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    fin >> N >> P >> C;
    for (int i = 0; i < N; ++i) {
        fin >> cow[i];
        fill_n(dis[cow[i]], P + 1, INF);
    }
    vector<vector<pair<int, int>>> graph(P + 1);
    for (int i = 0, u, v, d; i < C; ++i) {
        fin >> u >> v >> d;
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
    }

    vector<pair<int, int>> vec;
//    vec.reserve(C * 2);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq(greater<>(),vec);
    for (int n = 0; n < N; ++n) {
        if (dis[cow[n]][cow[n]] != INF) continue;
        vec.clear();
        pq.emplace(0, cow[n]);
        while (!pq.empty()) {
            int v, d;
            tie(d, v) = pq.top();
            pq.pop();
            if(dis[cow[n]][v]!=INF) continue;
            dis[cow[n]][v] = d;
            for (const auto &p : graph[v])
                if (dis[cow[n]][p.first]==INF) {
                    pq.emplace(d + p.second, p.first);
                }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= P; ++i) {
        int sum = 0;
        for (int j = 0; j <= N; ++j) {
            sum += dis[cow[j]][i];
        }
        ans = min(ans, sum);
    }
    fout << ans << endl;
    return 0;
}

