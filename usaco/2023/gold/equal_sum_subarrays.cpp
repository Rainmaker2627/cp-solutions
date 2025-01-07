#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

const int inf=1e18;

// can make O(n^2 log n) by lazily updating minimums but O(n^3) passes
signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), pre(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i+1]+=pre[i]+a[i];
    }
    
    vector<pair<int, pair<int, int>>> ss;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ss.push_back({pre[i]-pre[j], {j+1, i}});
        }
    } sort(ss.begin(), ss.end());

    int m=ss.size();
    vector<int> ans(n+1, inf);
    for (int i = 1; i < m; i++) {
        int d=ss[i].fi-ss[i-1].fi;
        auto r1=ss[i].se, r2=ss[i-1].se;
        if (r1.fi>r2.fi) swap(r1, r2);
        for (int j = r1.fi; j <= min(r1.se, r2.fi-1); j++) ans[j]=min(ans[j], d);

        if (r1.se>r2.se) swap(r1, r2);
        for (int j = max(r1.se+1, r2.fi); j <= r2.se; j++) ans[j]=min(ans[j], d);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}