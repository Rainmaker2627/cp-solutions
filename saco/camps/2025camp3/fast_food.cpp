#include<bits/stdc++.h>
using namespace std;

vector<int> cols, ans, par, h, t;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> qry;
void dfs1(int u, int p=0) {
    par[u]=p;
    h[u]=h[p]+1;
    for (auto v : adj[u]) {
        if (v==p) continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int p=0) {
    cols[t[u]]++;
    for (auto [c, i] : qry[u]) {
        if (c>0) ans[i]+=cols[c];
        else ans[i]-=cols[-c];
    }

    for (auto v : adj[u]) {
        if (v==p) continue;
        dfs2(v, u);
    } cols[t[u]]--;
}

int lg;
vector<vector<int>> sp;
int lca(int a, int b) {
    if (h[a]<h[b]) swap(a, b);
    int d=h[a]-h[b];
    for (int i = lg; i >= 0; i--) {
        if (d&(1<<i)) a=sp[a][i];
    } if (a==b) return a;
    for (int i = lg; i >= 0; i--) {
        if (sp[a][i]==sp[b][i]) continue;
        a=sp[a][i]; b=sp[b][i];
    } return sp[a][0];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
    cin >> n >> m;
    t.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    adj.assign(n+1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    par.assign(n+1, 0);
    h.assign(n+1, 0);
    dfs1(1);
    
    lg=0;
    while (n>>lg) lg++;
    sp.assign(n+1, vector<int>(lg+1, 0));
    for (int i = 1; i <= n; i++) sp[i][0]=par[i];
    for (int j = 1; j <= lg; j++) {
        for (int i = 1; i <= n; i++) {
            sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }

    qry.assign(n+1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int p=lca(a, b);
        qry[a].push_back({c, i});
        qry[b].push_back({c, i});
        qry[p].push_back({-c, i});
        qry[par[p]].push_back({-c, i});
    }

    cols.assign(n+1, 0);
    ans.assign(m, 0);
    dfs2(1, 1);

    for (auto i : ans) {
        cout << (i?'1':'0');
    } cout << '\n';

	return 0;
}