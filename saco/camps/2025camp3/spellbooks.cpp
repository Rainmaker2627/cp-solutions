#include<bits/stdc++.h>
using namespace std;
#define int long long

struct book {
    int a, b, h;
    bool operator<(book r) { return b>r.b; }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<book> v;
    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        v.push_back({a,b,h});
    } sort(v.begin(), v.end());
    
    vector<book> unq;
    unq.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i].b==unq.back().b) {
            unq.back().h+=v[i].h;
            unq.back().a=min(unq.back().a, v[i].a);
        } else unq.push_back(v[i]);
    }
    
    int ans=0;
    n=unq.size();
    stack<int> ms;
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        dp[i]=unq[i].h;
        while (!ms.empty() && unq[ms.top()].a>=unq[i].b) ms.pop();
        if (!ms.empty()) dp[i]+=dp[ms.top()];
        ans=max(ans, dp[i]);
        ms.push(i);
    } cout << ans << '\n';

    return 0;
}