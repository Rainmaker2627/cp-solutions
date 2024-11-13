#include<bits/stdc++.h>
using namespace std;

int n;
int r[200001];

int main() {
    cout.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i=1; i<n; i++) {
        r[i] = i+1;
    } r[n] = 1;

    int t = 1;
    while (r[t] != t) {
        cout << r[t] << ' ';
        t=r[t]=r[r[t]];
    } cout << t << '\n';

    return 0;
}