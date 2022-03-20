/*
ID: aleksil1
TASK: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int M, S, C, x;
    fin >> M >> S >> C;
    vector<int> v, dis;
    v.reserve(C);
    dis.reserve(C);
    for (int i = 0; i < C; ++i) {
        fin >> x;
        v.push_back(x);
    }
    std::sort(v.begin(), v.end());
    for (auto i = v.cbegin() + 1; i < v.cend(); ++i)
        dis.push_back(max(*i - *(i - 1) - 1, 0));
    std::sort(dis.rbegin(), dis.rend());
    int sum = v.back() - v.front() + 1;
    for (const auto d: dis) {
        if (M <= 1 || d == 0)
            break;
        sum -= d;
        M -= 1;
    }
    fout << sum << endl;
    return 0;
}

