/*
ID: aleksil1
TASK: fence6
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
using Edge = struct Edge {
    int len, n[2], con[2][8];
};
Edge edges[101];
int graph[101][101], dist[101][101], v[101][101], v_count, INF = INT_MAX / 3;


int main() {
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");

    fin >> N;
    for (int i = 1, t; i <= N; ++i) {
        fin >> t;
        auto &e = edges[t];
        fin >> e.len >> e.n[0] >> e.n[1];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < e.n[j]; ++k) {
                fin >> e.con[j][k];
            }
        }
    }

    fill_n((int *) graph, 101 * 101, INF);
//    for (int i = 0; i < 101; ++i) {
//        graph[i][i] = 0;
//    }

    for (int i = 1; i <= N; ++i) {
        int t[2]{};
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < edges[i].n[j]; ++k) {
                if (v[edges[i].con[j][k]][i]) {
                    t[j] = v[edges[i].con[j][k]][i];
                    break;
                }
            }
        }
        t[0] = t[0] ? t[0] : ++v_count;
        t[1] = t[1] ? t[1] : ++v_count;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < edges[i].n[j]; ++k) {
                v[i][edges[i].con[j][k]] = t[j];
            }
        }
        graph[t[0]][t[1]] = graph[t[1]][t[0]] = edges[i].len;
    }

    memcpy(dist, graph, sizeof graph);

    int ans = INT_MAX;
    for (int k = 1; k <= v_count; ++k) {
        for (int i = 1; i <= v_count; ++i) {
            for (int j = 1; j <= v_count; ++j) {
                if (i != j) {
                    ans = min(ans, dist[i][j] + graph[i][k] + graph[k][j]);
                }
            }
        }
        for (int i = 1; i <= v_count; ++i) {
            for (int j = 1; j <= v_count; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    fout << ans << endl;
    return 0;
}

