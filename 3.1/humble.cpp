/*
ID: aleksil1
TASK: humble
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("humble.in");
ofstream fout("humble.out");

int K, N;
long long prime[100];

int main() {
    fin >> K >> N;
    for (int i = 0; i < K; ++i) {
        fin >> prime[i];
    }
    sort(prime, prime + K, greater<>());
    using Pair = pair<int, int>;
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(1, 0);
    while (N--) {
        int num, i;
        tie(num, i) = pq.top();
        fout << pq.top().first << endl;
        pq.pop();
        for (int j = i; j < K && num * prime[j] <= INT_MAX; ++j) {
            pq.emplace(num * prime[j], j);
        }
    }
    fout << pq.top().first << endl;
    return 0;
}

