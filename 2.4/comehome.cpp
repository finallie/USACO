/*
ID: aleksil1
TASK: comehome
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Vertex = pair<int, char>;

ifstream fin("comehome.in");
ofstream fout("comehome.out");


int main() {
    int P, d;
    char v, u;
    unordered_map<char, vector<Vertex>> graph;
    fin >> P;
    while (P--) {
        fin >> v >> u >> d;
        graph[v].emplace_back(d, u);
        graph[u].emplace_back(d, v);
    }
    priority_queue<Vertex, vector<Vertex>, greater<>> priorityQueue;
    priorityQueue.push({0, 'Z'});
    while (true) {
        tie(d, v) = priorityQueue.top();
        if (isupper(v) && v != 'Z') {
            fout << v << ' ' << d << endl;
            break;
        }
        priorityQueue.pop();
        for (const auto &t: graph[v])
            priorityQueue.emplace(t.first + d, t.second);
        graph[v].clear();
    }
    return 0;
}

