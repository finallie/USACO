/*
ID: aleksil1
TASK: fence
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

multiset<int> adj[501];
vector<int> path;

void find_circuit(int i) {
    while (!adj[i].empty()) {
        auto p = adj[i].begin();
        int j = *p;
        adj[j].erase(adj[j].find(i));
        adj[i].erase(p);
        find_circuit(j);
    }
    path.push_back(i);
}


int main() {
    ifstream fin("fence.in");
    ofstream fout("fence.out");

    int F, start;
    map<int, int> degree;
    fin >> F;
    while (F--) {
        int u, v;
        fin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u] ^= 1;
        degree[v] ^= 1;
    }

    start = degree.begin()->first;
    for (const auto &p: degree) {
        if (p.second == 1) {
            start = p.first;
            break;
        }
    }
    find_circuit(start);
    for (auto i = path.rbegin(); i != path.rend(); ++i)
        fout << *i << endl;

    return 0;
}

