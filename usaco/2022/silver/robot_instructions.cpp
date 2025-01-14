#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> pii;
pii operator+(pii a, pii b) { return {a.first + b.first, a.second + b.second}; }
pii operator-(pii a, pii b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<pii, int>> get(vector<pii>& sub) {
    int n=sub.size();
    vector<pair<pii, int>> a;
    a.push_back({{0, 0}, 0});
    for (int i = 0; i < n; i++) {
        int v=a.size();
        for (int j = 0; j < v; j++) {
            a.push_back({a[j].first+sub[i], a[j].second+1});
        }
    } sort(a.begin(), a.end());
    return a;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    pii final;
    cin >> n >> final.first >> final.second;
    vector<pair<int, int>> sub;
    vector<pair<pii, int>> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        sub.push_back({x, y});
        if (i==n/2) {
            a=get(sub);
            sub.clear();
        }
    } b=get(sub);
    reverse(b.begin(), b.end());

    int ib=0;
    pii cur, prev{1e18, 1e18};
    vector<int> ans(n+1, 0), cnt;
    for (auto [i, j] : a) {
        cur=final-i;
        if (cur!=prev) {
            prev=cur;
            cnt.assign(n-n/2+1, 0);
            while (ib<b.size() && b[ib].first>cur) ib++;
            while (ib<b.size() && b[ib].first==cur) {
                cnt[b[ib++].second]++;
            }
        }
        for (int i = 0; i < cnt.size(); i++) {
            ans[i+j]+=cnt[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}