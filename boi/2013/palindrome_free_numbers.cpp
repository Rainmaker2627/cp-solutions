#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> d;
int dp[20][11][11][2];
int ans(int pos, int d1, int d2, bool ok) {
    int& res=dp[pos][d1][d2][ok];
    if (pos==d.size()) return 1;
    if (res>-1) return res;
    else res=0;
    if (ok) {
        for (int i = 0; i < 10; i++) {
            if (i==d1 || i==d2) continue;
            res+=ans(pos+1, d2, i, ok);
        }
    } else {
        for (int i = 0; i <= d[pos]; i++) {
            if (i==d1 || i==d2) continue;
            res+=ans(pos+1, d2, i, i!=d[pos]);
        }
    } return res;
}

int ans(int x) {
    if (x<100) return x+1-x/11;
    d.clear();
    while (x) {
        d.push_back(x%10);
        x/=10;
    } reverse(d.begin(), d.end());
    memset(dp, -1, sizeof(dp));
    int res=0;
    for (int i = 0; i < d.size(); i++) {
        res+=ans(i, (i+1==d.size()?10:0), 10, i>0);
    } return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int l, r;
    cin >> l >> r;
    cout << ans(r)-ans(l-1) << '\n';

    return 0;
}