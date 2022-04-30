/*
ID: aleksil1
TASK: buylow
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using BigInt = struct BigInt {
    vector<int> v;

    BigInt() = default;

    BigInt(int i) {
        while (i) {
            v.push_back(i % 10);
            i /= 10;
        }
        if (v.empty()) {
            v.push_back(0);
        }
    }
};

vector<int> seq;
vector<vector<pair<int, BigInt>>> vec;

BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
    BigInt result;
    int t = 0, i;
    for (i = 0; i < min(lhs.v.size(), rhs.v.size()); ++i) {
        t = lhs.v[i] + rhs.v[i] + t;
        result.v.push_back(t % 10);
        t /= 10;
    }
    while (i < lhs.v.size()) {
        t = lhs.v[i] + t;
        result.v.push_back(t % 10);
        t /= 10;
        ++i;
    }
    while (i < rhs.v.size()) {
        t = rhs.v[i] + t;
        result.v.push_back(t % 10);
        t /= 10;
        ++i;
    }
    if (t)
        result.v.push_back(t);
    return result;
}

ostream &operator<<(ostream &out, const BigInt &b) {
    for (auto it = b.v.crbegin(); it != b.v.crend(); ++it) {
        out << *it;
    }
    return out;
}

void add(int index, int t) {
    if (vec.size() == index)
        vec.emplace_back();
    BigInt acc = 0;
    if (index != 0) {
        auto &v = vec[index - 1];
        auto it = std::upper_bound(v.begin(), v.end(), make_pair(t, 0), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        for (; it != v.end(); ++it)
            acc = acc + it->second;
    } else {
        acc = 1;
    }
    if (!vec[index].empty() && vec[index].back().first == t) {
        vec[index].back().second = acc;
    } else {
        vec[index].emplace_back(t, acc);
    }
}

void add(int t) {
    auto it = std::lower_bound(seq.begin(), seq.end(), t, greater<>());
    if (it == seq.end()) {
        it = seq.insert(it, t);
    } else {
        *it = t;
    }
    add(it - seq.begin(), t);
}


int main() {
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");

    int N, t;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> t;
        add(t);
    }

    fout << vec.size() << ' '
         << accumulate(vec.back().begin(), vec.back().end(), BigInt(0),
                       [](BigInt acc, auto &p) { return acc + p.second; })
         << endl;

    return 0;
}

