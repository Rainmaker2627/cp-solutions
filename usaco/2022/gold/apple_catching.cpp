#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

struct query {
    int q, t, x, n;
    bool operator<(query b) { return (x+t==b.t+b.x?q<b.q:x+t<b.x+b.t); }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<query> q;
    for (int i = 0; i < n; i++) {
        int a, t, x, n;
        cin >> a >> t >> x >> n;
        q.push_back({a, t, x, n});
    } sort(q.begin(), q.end());

    int ans=0;
    set<pair<int, int>> s;
    s.insert({inf, 0});
    for (auto i : q) {
        auto [a, t, x, n]=i;
        if (a==1) {
            if (s.count({x-t, n})) {
                s.erase({x-t, n});
                s.insert({x-t, 2*n});
            } else s.insert({x-t, n});
        } else {
            auto p=s.lower_bound({x-t, 0});
            while (p->first<inf && p->second<n) {
                ans+=p->second;
                n-=p->second;
                p=s.erase(p);
            }
            if (p->first<inf && p->second>=n) {
                s.insert({p->first, p->second-n});
                s.erase(p);
                ans+=n;
            }
        }
    } cout << ans << '\n';

    return 0;
}