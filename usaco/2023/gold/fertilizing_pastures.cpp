#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=2e18;
vector<int> rt, fr, fs, mp, sz, ig;
vector<vector<int>> adj;
bool tcomp(int u, int v) { return sz[u]*ig[v]<sz[v]*ig[u]; }
void dfs(int u) {
    ig[u]=rt[u];
    if (adj[u].empty()) return;
    vector<int> t;
    for (auto v : adj[u]) {
        dfs(v);
        sz[u]+=sz[v];
        ig[u]+=ig[v];
        fr[u]+=fr[v];
        t.push_back(v);
        mp[u]=max(mp[u], mp[v]+1);
    } sort(t.begin(), t.end(), tcomp);
    int ct=1, rs=0, aw=0;
    for (auto v : t) {
        fr[u]+=ct*ig[v];
        ct+=2*sz[v];
        aw+=ig[v];
    } ct=1; fs[u]=inf;
    for (auto v : t) {
        aw-=ig[v];
        if (mp[v]+1==mp[u]) fs[u]=min(fs[u], fr[u]-fr[v]-ct*ig[v]-2*sz[v]*aw+fs[v]+ig[v]*(2*sz[u]-2*sz[v]-1));
        ct+=2*sz[v];
        rs+=ct*ig[v];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    rt.assign(n+1, 0);
    adj.assign(n+1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int p, a;
        cin >> p >> a;
        adj[p].push_back(i);
        rt[i]=a;
    }

    sz.assign(n+1, 1);
    ig.assign(n+1, 0);
    fr.assign(n+1, 0);
    fs.assign(n+1, 0);
    mp.assign(n+1, 1);
    dfs(1);

    if (t) cout << 2*sz[1]-mp[1]-1 << ' ' << fs[1] << '\n';
    else cout << 2*sz[1]-2 << ' ' << fr[1] << '\n';

    return 0;
}