#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> par1(n+1, 0);
        vector<vector<int>> adj1(n+1, vector<int>());
        for (int i = 0; i < n-1; i++) {
            int v, p;
            cin >> v >> p;
            par1[v]=p;
            adj1[p].push_back(v);
        }

        int r=0;
        for (int i = 1; i <= n; i++) r=(par1[i]==0?i:r);
        vector<int> dep(n+1, 1);
        vector<vector<int>> nbd{{r}};
        for (int i = 0; i < nbd.size(); i++) {
            if (nbd[i].size()) nbd.push_back(vector<int>());
            for (auto u : nbd[i]) {
                for (auto v : adj1[u]) {
                    nbd[i+1].push_back(v);
                    dep[v]=i+1;
                }
            }
        } nbd.pop_back();

        int m;
        cin >> m;
        vector<int> par2(n+1, 0);
        vector<vector<int>> adj2(n+1, vector<int>());
        for (int i = 0; i < m-1; i++) {
            int v, p;
            cin >> v >> p;
            par2[v]=p;
            adj2[p].push_back(v);
        } par2[r]=r;

        int d=nbd.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        for (int i = d-1; i > 0; i--) {
            for (auto u : nbd[i]) {
                if (par2[u]) { dp[u][u]=true; continue; }
                for (auto v : nbd[i]) {
                    if (!par2[v] || u>v) continue;
                    dp[u][v]=true;
                    for (auto c : adj1[u]) {
                        bool ok=false;
                        for (auto d : adj2[v]) {
                            ok|=dp[c][d];
                        } dp[u][v]=ok;
                        if (!dp[u][v]) break;
                    }
                }
            }
        }

        cout << n-m << '\n';
        vector<int> mp(n+1, 0); mp[r]=r;
        for (int i = 0; i < d; i++) {
            for (auto u : nbd[i]) {
                for (auto v : nbd[i]) {
                    if (dp[u][v] && par2[v]==mp[par1[u]]) {
                        mp[u]=v;
                        break;
                    }
                }
                if (mp[u] && mp[u]!=u) cout << u << ' ' << mp[u] << '\n';
            }
        }
    }

    return 0;
}