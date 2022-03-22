/*
ID: aleksil1
TASK: combo
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

set<int> s;
int N;

int mode(int i) {
    return (i - 1 + N) % N;
}

void push(int a, int b, int c){
    for (int i = -2; i <=2 ; ++i) {
        for (int j = -2; j <=2; ++j) {
            for (int k = -2; k <= 2; ++k) {
                s.insert(mode(a + i) * 10000 + mode(b + j) * 100 + mode(c + k));
            }
        }
    }
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int a, b, c;
    fin >> N >> a >> b >> c;
    push(a, b, c);
    fin >> a >> b >> c;
    push(a, b, c);
    fout << s.size() << endl;
    return 0;
}

