#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        c.push_back({-x, y});
    } sort(c.begin(), c.end());
    
    int x=0;
    queue<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        int f=0;
        auto [w, a]=c[i];
        while (!t.empty()) {
            auto [h, n]=t.front();
            if (h+k>w) break;
            if (n>=a) {
                t.front().second-=a;
                f+=a; a=0;
                break;
            } else {
                f+=n; a-=n;
                t.pop();
            }
        }
        f+=min(m, a); m-=min(m, a);
        t.push({w, f});
        x+=f;
    } cout << x << '\n';

    return 0;
}