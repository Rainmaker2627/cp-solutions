#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, n, k;
    cin >> t >> n >> k;
    vector<int> x(n), y(n), s{0};
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (i && x[i-1]+k<x[i]) s.push_back(i);
    } s.push_back(n);
    int m=s.size(), a=0;
    
    if (t==1) {
        for (int i = 0; i < m-1; i++) {
            if ((s[i+1]-s[i])%2==0) continue;
            int r=min(y[s[i]], y[s[i+1]-1]);
            for (int j = s[i]+1; j < s[i+1]-1; j++) {
                if (x[j-1]+k<x[j+1] && (j-s[i])%2==1) continue;
                r=min(r, y[j]);
            } a+=r;
        } cout << a << '\n';
    } else {
        // some dp ill implement eventually
    }

    return 0;
}