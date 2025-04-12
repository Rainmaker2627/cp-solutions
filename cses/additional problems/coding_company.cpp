#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, x, s=0;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        s+=t[i];
    } sort(t.begin(), t.end());
    
    vector<vector<int>> a(1, vector<int>(s+x+1, 0)), b; a[0][s]=1;
    for (int i = 0; i < n; i++) {
        b.assign(min(i, n-i)+2, vector<int>(s+x+1, 0));
        for (int k = 0; k <= min(i, n-i); k++) {
            for (int v = 0; v <= s+x; v++) {
                int r=a[k][v];
                if (r==0) continue;
                b[k][v]+=(k+1)*r%mod;
                b[k+1][v-t[i]]+=r;
                if (k>0 && v+t[i]<=s+x) b[k-1][v+t[i]]+=k*r%mod;
            }
        } swap(a, b);
    }

    int ans=0;
    for (auto i : a[0]) {
        ans=(ans+i)%mod;
    } cout << ans << '\n';

    return 0;
}