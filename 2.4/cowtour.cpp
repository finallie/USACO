/*
ID: aleksil1
TASK: cowtour
LANG: C++
*/
#include <bits/stdc++.h>

#define INF (1e20)

using namespace std;
using ll = long long;

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

using Point = struct Point {
    int x, y;
};

int N;
Point points[150];
double gragh[150][150];
double msd[150];
int field[150];
double diam[150];

double dis(const Point &a, const Point &b) {
    return sqrt((double) (a.x - b.x) * (a.x - b.x) + (double) (a.y - b.y) * (a.y - b.y));
}

void build_field(int i, int n) {
    for (int j = 0; j < N; ++j) {
        if (gragh[i][j] != INF)
            field[j] = n;
    }
}


int main() {
    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> points[i].x >> points[i].y;
    }

    fin.get();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            gragh[i][j] = (fin.get() - '0');
        }
        fin.get();
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            gragh[i][j] = gragh[j][i] = (gragh[i][j] == 0 ? INF : dis(points[i], points[j]));
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                gragh[i][j] = min(gragh[i][j], gragh[i][k] + gragh[k][j]);
            }
        }
    }
    for (int i = 0, n = 0; i < N; ++i) {
        if (field[i] == 0)
            build_field(i, ++n);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (gragh[i][j] != INF)
                msd[i] = max(msd[i], gragh[i][j]);
        }
        diam[field[i]] = max(diam[field[i]], msd[i]);
    }
    double ans = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i] == field[j]) continue;
            double t = max(max(diam[field[i]], diam[field[j]]), msd[i] + msd[j] + dis(points[i], points[j]));
            ans = min(t, ans);
        }
    }
    fout << setprecision(6) << fixed << ans << endl;
    return 0;
}

