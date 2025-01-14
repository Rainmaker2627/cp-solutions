#include<bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
    vector<int> r, s;

    dsu(int n) {
        r.assign(n+1, -1);
        s.assign(n+1, 1);
    }

    int find(int a) {
        if (r[a]==-1) return a;
        return r[a]=find(r[a]);
    }

    bool unite(int a, int b) {
        a=find(a); b=find(b);
        if (a==b) return false;
        if (s[a]<s[b]) swap(a, b);
        s[a]+=s[b]; r[b]=a;
        return true;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> cow(11, vector<int>());
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cow[y].push_back(x);
    }

    vector<int> pnt(11, -1);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 11; i++) {
        if (cow[i].empty()) continue;
        sort(cow[i].begin(), cow[i].end());
        pq.push({-cow[i][++pnt[i]], i});
    }
    
    int t=0, p=1e7;
    unordered_map<int, int> id;
    vector<pair<int, pair<int, int>>> edge;
    while (!pq.empty()) {
        auto [x, i]=pq.top();
        pq.pop();
        id[i*p-x]=t++;
        for (int j = 0; j < 11; j++) {
            if (pnt[j]<1) continue;
            int x2=cow[j][pnt[j]-1];
            edge.push_back({(x+x2)*(x+x2)+(i-j)*(i-j), {t-1, id[j*p+x2]}});
        }
        if (++pnt[i]==cow[i].size()) continue;
        else pq.push({-cow[i][pnt[i]], i});
    } sort(edge.begin(), edge.end());

    dsu uf(t);
    int ans=0;
    for (auto [d, p] : edge) {
        auto [a, b]=p;
        if (uf.unite(a, b)) ans+=d;
    } cout << ans << '\n';

    return 0;
}