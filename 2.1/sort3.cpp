/*
ID: aleksil1
TASK: sort3
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

size_t N;
int ints[1000];
int sum[4]{}, place[4][4]{};

int main() {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> ints[i];
        sum[ints[i]]++;
    }
    for (int i = 1, k = 0; i <= 3; ++i) {
        for (int j = 0; j < sum[i]; ++j) {
            place[i][ints[k++]]++;
        }
    }
    int x = min(place[1][2], place[2][1]), y = min(place[1][3], place[3][1]), z = min(place[2][3], place[3][2]);
    fout << x + y + z + 2 * (place[1][2] + place[1][3] - x - y) << endl;
    return 0;
}

