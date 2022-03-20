/*
ID: aleksil1
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

int N;

using Square = vector<string>;

bool f1(const Square &s1, const Square &s2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (s1[i][j] != s2[j][N - 1 - i])
                return false;
        }
    }
    return true;
}

bool f2(const Square &s1, const Square &s2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (s1[i][j] != s2[N - 1 - i][N - 1 - j])
                return false;
        }
    }
    return true;
}

bool f3(const Square &s1, const Square &s2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (s1[i][j] != s2[N - 1 - j][i])
                return false;
        }
    }
    return true;
}

bool f4(const Square &s1, const Square &s2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (s1[i][j] != s2[i][N - 1 - j])
                return false;
        }
    }
    return true;
}

bool f5(const Square &s1, const Square &s2) {
    Square t;
    for (const auto &e : s1)
        t.emplace_back(e.crbegin(), e.crend());
    return f1(t, s2) || f2(t, s2) || f3(t, s2) || f4(t, s2);
}

bool f6(const Square &s1, const Square &s2) {
    return s1 == s2;
}

Square getSquare() {
    Square s(N);
    for (int i = 0; i < N; ++i) {
        fin >> s[i];
    }
    return s;
}

int main() {
    fin >> N;
    Square s1 = getSquare(), s2 = getSquare();
    int ans;
    if (f1(s1, s2)) {
        ans = 1;
    } else if (f2(s1, s2)) {
        ans = 2;
    } else if (f3(s1, s2)) {
        ans = 3;
    } else if (f4(s1, s2)) {
        ans = 4;
    } else if (f5(s1, s2)) {
        ans = 5;
    } else if (f6(s1, s2)) {
        ans = 6;
    } else {
        ans = 7;
    }
    fout << ans << endl;
    return 0;
}

