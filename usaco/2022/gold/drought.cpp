#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, b=1e9;
    cin >> n;
    vector<int> h(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        b=min(b, h[i]);
    }

    if (n==1) cout << h[0] << '\n';
    else {
        int ans=0;
        if (n%2==0) b=0;
        for (int k = 0; k <= b; k++) {
            if (k) for (int i = 0; i < n; i++) h[i]--;
            int s=1, r=0;
            vector<int> p(h[0]+1, 0), c; p[0]=1;
            for (int i = 1; i < n; i++) {
                c.assign(h[i]+1, 0);
                for (int j = 0; j <= min(h[i-1], h[i]); j++) {
                    c[j]=s;
                    r=(r+s)%mod;
                    s=(s-p[h[i-1]-j]+mod)%mod;
                } swap(p, c);
                s=r; r=0;
            } ans=(ans+s)%mod;
        } cout << ans << '\n';
    }

    return 0;
}