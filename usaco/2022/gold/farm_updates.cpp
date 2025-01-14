#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<int> ans;
vector<vector<int>> adj;
void dfs(int u, int t) {
    if (ans[u]<inf) return;
    else ans[u]=t;
    for (auto v : adj[u]) {
        dfs(v, t);
    }
}

struct query {
    char c;
    int t;
    query(char _c, int _t) {
        c=_c; t=_t;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<query> qs;
    vector<pair<int, int>> r;
    vector<bool> act(n+1, true), in;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c=='A') {
            int x, y;
            cin >> x >> y;
            in.push_back(true);
            r.push_back({x, y});
            qs.emplace_back(c, r.size()-1);
        } else {
            int x;
            cin >> x;
            if (c=='D') {
                qs.emplace_back(c, x);
                act[x]=false;
            } else {
                qs.emplace_back(c, x-1);
                in[x-1]=false;
            }
        }
    } reverse(qs.begin(), qs.end());

    adj.assign(n+1, vector<int>());
    for (int i = 0; i < r.size(); i++) {
        if (!in[i]) continue;
        auto [u, v]=r[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans.assign(n+1, inf);
    for (int i = 1; i <= n; i++) {
        if (act[i]) dfs(i, 0);
    }

    for (int i = 0; i < q; i++) {
        if (qs[i].c=='D') {
            dfs(qs[i].t, i+1);
        } else if (qs[i].c=='R') {
            int t=i+1;
            auto [u, v]=r[qs[i].t];
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (ans[u]==inf) {
                if (ans[v]<inf) dfs(u, i+1);
            } else if (ans[v]==inf) dfs(v, i+1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << q-ans[i] << '\n';
    }

    return 0;
}