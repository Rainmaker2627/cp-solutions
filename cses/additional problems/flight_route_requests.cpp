#include<bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p, s, c;

    dsu(int n) {
        p.assign(n+1, -1);
        s.assign(n+1, 1);
    }

    int find(int a) {
        if (p[a]==-1) return a;
        return p[a]=find(p[a]);
    }

    void unite(int a, int b) {
        a=find(a); b=find(b);
        if (a==b) return;
        if (s[a]<s[b]) swap(a, b);
        p[b]=a; s[a]+=s[b];
    }
};

vector<int> vis;
vector<vector<int>> adj;
int dfs(int u) {
    vis[u]=1;
    for (auto v : adj[u]) {
        if (vis[v]==2) continue;
        if (vis[v]==1 || dfs(v)) return 1;
    } vis[u]=2;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    dsu uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        uf.unite(a, b);
    }

    map<int, int> id;
    vector<vector<int>> cc{{0}};
    for (int i = 1; i <= n; i++) {
        int r=uf.find(i);
        if (!id[r]) {
            id[r]=cc.size();
            cc.push_back({i});
        } else {
            cc[id[r]].push_back(i);
        }
    }
    
    int ans=0;
    vis.assign(n+1, 0);
    for (auto i : cc) {
        int r=0;
        for (auto u : i) {
            if (vis[u]) continue;
            if (r=dfs(u)) break;
        } ans+=i.size()-(1-r);
    } cout << ans << '\n';

    return 0;
}