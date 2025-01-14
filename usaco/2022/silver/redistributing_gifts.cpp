#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

vector<bool> vis;
vector<vector<int>> fwd, rev;
void dfs(int u, vector<int>& ord, vector<vector<int>>& adj) {
    vis[u]=true;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        dfs(v, ord, adj);
    } ord.push_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    fwd.assign(n+1, vector<int>());
    rev.assign(n+1, vector<int>());
    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        bool b=false;
        for (int j = 1; j <= n; j++) {
            int k;
            cin >> k;
            pref[i][k]=j;
            if (k==i) b=true;
            if (b) continue;
            fwd[i].push_back(k);
            rev[k].push_back(i);
        }
    }
    
    vector<int> ord;
    vis.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, ord, rev);
    } reverse(ord.begin(), ord.end());
    vis.assign(n+1, false);
    vector<int> ans(n+1, 0);
    for (auto u : ord) {
        if (vis[u]) continue;
        vector<int> cmp;
        dfs(u, cmp, fwd);
        for (auto v : cmp) {
            int m=inf;
            for (auto s : cmp) {
                if (pref[v][s]<m) {
                    m=pref[v][s];
                    ans[v]=s;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    

    return 0;
}