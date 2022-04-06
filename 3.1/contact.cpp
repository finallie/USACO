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

string to_binary(int n) {
    string s;
    while (n != 1) {
        s += (char) ('0' + (n % 2));
        n /= 2;
    }
    std::reverse(s.begin(), s.end());
    return s;
}


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
        auto len1 = get<1>(a).size(), len2 = get<1>(b).size();
        return tie(get<0>(a), len2, get<1>(b)) < tie(get<0>(b), len1, get<1>(a));
    };
    priority_queue<tuple3, vector<tuple3>, decltype(cmp)> pq(cmp);
    for (int i = 1 << A; i < (1 << (A + 1)); ++i) {
        if (num[i]) {
            pq.emplace(num[i], to_binary(i), i);
        }
    }
    while (!pq.empty() && N--) {
        int i, j, k = 1;
        tie(i, s, j) = pq.top();
        pq.pop();
        fout << i << '\n';
        fout << s;
        while (true) {
            if (j < (1 << B)) {
                if (num[j * 2]) {
                    pq.emplace(num[j * 2], s + '0', j * 2);
                }
                if (num[j * 2 + 1]) {
                    pq.emplace(num[j * 2 + 1], s + '1', j * 2 + 1);
                }
            }
            if (!pq.empty() && get<0>(pq.top()) == i) {
                tie(i, s, j) = pq.top();
                pq.pop();
                if (++k % 6 != 1) fout << ' ';
                fout << s;
                if (k % 6 == 0) fout << '\n';
            } else {
                break;
            }
        }
        if (k % 6 != 0) fout << '\n';
    }
    fout << flush;
    return 0;
}

