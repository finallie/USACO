/*
ID: aleksil1
TASK: skidesign
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    fin >> N;
    vector<int> hills(N);
    for (int i = 0; i < N; ++i) {
        fin >> hills[i];
    }
    auto pair = std::minmax_element(hills.begin(), hills.end());
    int ans = INT32_MAX;
    for (int min = *pair.first, max = min + 17; max <= *pair.second; ++min, ++max) {
        int sum = 0;
        for (const auto &h: hills) {
            if (h < min) {
                sum += (min - h) * (min - h);
            } else if (h > max) {
                sum += (h - max) * (h - max);
            }
        }
        ans = std::min(ans, sum);
    }
    fout << ans << endl;
    return 0;
}

