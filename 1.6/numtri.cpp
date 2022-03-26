/*
ID: aleksil1
TASK: numtri
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int R;
int a[1001]{},b[1001]{};


int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin >> R;
    for (int i = 1; i <=R ; ++i) {
        for (int j = 1; j <=i ; ++j) {
            fin >> b[j];
            b[j] += max(a[j], a[j - 1]);
        }
        swap(a, b);
    }
    fout << *max_element(begin(a) + 1, begin(a) + R + 1) << endl;
    return 0;
}

