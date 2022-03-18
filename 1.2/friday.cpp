/*
ID: aleksil1
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

inline int next(int weekday, int n) {
    return (weekday + n) % 7;
}

inline bool isLeap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

constexpr int start = (2 - 31 + 12) % 7 + 7;

int months[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main() {
    ifstream fin("friday.in");
    int n;
    fin >> n;
    int week[7]{};
    for (int i = 0, w = start; i < n; ++i) {
        for (int j = 0; j < 12; ++j) {
            w = next(w, months[(j + 11) % 12]);
            if (j == 2 && isLeap(1900 + i))
                w = (w + 1) % 7;
            week[w]++;
        }
    }
    ofstream fout("friday.out");
    string ans;
    for (const auto &w: week)
        ans += to_string(w) + ' ';
    ans.pop_back();
    fout << ans << endl;
    return 0;
}