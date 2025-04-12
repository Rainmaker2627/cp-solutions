#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, s=0;
        cin >> n;
        vector<int> a(n/2+1, 0), b(n/2+1, 0);
        for (int i = 1; i <= n/2; i++) {
            cin >> a[i];
            a[i]+=a[i-1];
        } s+=a[n/2];
        for (int i = 0; i < n/2; i++) cin >> b[i];
        reverse(b.begin(), b.end());
        for (int i = 1; i <= n/2; i++) b[i]+=b[i-1];
        s+=b[n/2];

        int ans=0;
        for (int i = 0; i < n/2; i++) {
            ans=max(ans, a[i]+b[n/2-i-1]);
        } cout << s-ans << ' ' << ans << '\n';
    }

    return 0;
}