#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if (n<m) cout << 0 << '\n';
    else {
        vector<int> c(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        vector<int> deg(n+1, 0);
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            deg[u]++; deg[v]++;
        }

        queue<int> top;
        vector<int> ans(m);
        for (int i = 1; i <= n; i++) if (deg[i]==1) top.push(i);
        while (!top.empty()) {
            auto u=top.front(); top.pop();
            if (deg[u]==-1) continue;
            for (auto [v, i] : adj[u])  {
                if (deg[v]<0) continue;
                if (--deg[v]==1) top.push(v);
                ans[i]=c[u];
                c[v]-=c[u];
            } n--;
            deg[u]=-1;
        }

        if (n%2==0 & n!=0) cout << 0 << '\n';
        else {
            if (n) {
                int s=0;
                for (int i = 1; i <= n && !s; i++){
                    if (deg[i]>0) s=i;
                }
                
                int u=s, p=0, tl=0, ev=0;
                vector<pair<int, int>> ord;
                while (n) {
                    deg[u]=-1;
                    for (auto [v, i] : adj[u]) {
                        if (deg[v]<0) continue;
                        ord.push_back({u, i});
                        u=v; n--; p=!p;
                        if (!p) ev+=c[v];
                        tl+=c[v];
                        break;
                    } if (n==1) { deg[s]=1; } 
                }

                n=ord.size();
                ans[ord[0].second]=tl/2-ev;
                for (int i = 1; i < n; i++) {
                    ans[ord[i].second]=c[ord[i].first]-ans[ord[i-1].second];
                }
            }

            for (int i = 0; i < m; i++) {
                cout << 2*ans[i] << '\n';
            }
        }
    }

    return 0;
}