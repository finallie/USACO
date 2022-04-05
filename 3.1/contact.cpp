/*
ID: aleksil1
TASK: contact
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, string, int> tuple3;

ifstream fin("contact.in");
ofstream fout("contact.out");

int num[1 << 13], A, B, N;


int main() {
    fin >> A >> B >> N;
    string s, t;
    while (fin >> t)
        s += t;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0, k = 1; j < B && i + j < s.size(); ++j) {
            k = (k << 1) + (s[i + j] - '0');
            num[k]++;
        }
    }
    auto cmp = [](const tuple3 &a, const tuple3 &b) {
        return tie(get<0>(a), get<1>(b)) < tie(get<0>(b), get<1>(a));
    };
    priority_queue<tuple3, vector<tuple3>, decltype(cmp)> pq(cmp);
    for (int i = 1<<A; i <(1<<(A+1)) ; ++i) {
        if (num[i]) {

        }
    }
    return 0;
}

