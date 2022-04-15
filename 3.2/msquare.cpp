/*
ID: aleksil1
TASK: msquare
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using array8 = array<char, 8>;
int target;
constexpr int max_index = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
pair<int, char> pre[max_index];

int index(array8 a) {
    static constexpr int product[8]{7 * 6 * 5 * 4 * 3 * 2 * 1, 6 * 5 * 4 * 3 * 2 * 1, 5 * 4 * 3 * 2 * 1, 24,
                                    6, 2, 1, 1};
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += a[i] * product[i];
        for (int j = i + 1; j < 8; ++j) {
            if (a[j] > a[i]) {
                a[j]--;
            }
        }
    }
    return sum;
}

int transfer_index[3][8]{{7, 6, 5, 4, 3, 2, 1, 0},
                         {3, 0, 1, 2, 5, 6, 7, 4},
                         {0, 6, 1, 3, 4, 2, 5, 7}};
char transfer_id[3]{'A', 'B', 'C'};

array8 transfer(const array8 &a, int *p) {
    array8 b;
    for (int i = 0; i < 8; ++i) {
        b[i] = a[p[i]];
    }
    return b;
}

int main() {
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");

    array8 temp;
    for (int i = 0; i < 8; ++i) {
        fin >> temp[i];
        temp[i] -= '1';
    }
    target = index(temp);
    if (target == 0) {
        fout << 0 << endl;
        fout << endl;
        return 0;
    }

    pre[0] = {0, ' '};
    deque<pair<array8, int>> q;
    q.emplace_back(array8{0, 1, 2, 3, 4, 5, 6, 7}, 0);
    while (!q.empty()) {
        for (int i = 0; i < 3; ++i) {
            auto a = transfer(q.front().first, transfer_index[i]);
            auto ind = index(a);
            if (pre[ind].second == 0) {
                pre[ind] = {q.front().second, transfer_id[i]};
                if (ind == target) {
                    string s;
                    while (ind) {
                        s += pre[ind].second;
                        ind = pre[ind].first;
                    }
                    std::reverse(s.begin(), s.end());
                    fout << s.size() << endl;
                    fout << s << endl;
                    exit(EXIT_SUCCESS);
                }
                q.emplace_back(a, ind);
            }
        }
        q.pop_front();
    }
    return 0;
}

