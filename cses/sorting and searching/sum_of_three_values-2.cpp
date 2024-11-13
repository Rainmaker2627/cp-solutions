#include<bits/stdc++.h>
using namespace std;
#define int long long

struct res {
	int a=-1, b=-1, c=-1;
	void set(int p, int q, int r) { a=p; b=q; c=r; }
};

res find(int x, vector<pair<int, int>>& a) {
	res r;
	int n=a.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (x<a[i].first+a[j].first) continue;
			pair<int, int> t={x-a[i].first-a[j].first, 0};
			auto k=lower_bound(a.begin(), a.end(), t);
			if ((*k).first==t.first) {
				while (((*k).second==a[i].second || (*k).second==a[j].second) && k!=a.end()) k++;
				if ((*k).first!=t.first || k==a.end()) continue;
				r.set(a[i].second, a[j].second, (*k).second);
				return r;
			}
		}
	} return r;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second=i+1;
	} sort(a.begin(), a.end());

	res r=find(x, a);
	if (r.a==-1) cout << "IMPOSSIBLE\n";
	else cout << r.a << ' ' << r.b << ' ' << r.c << '\n';

	return 0;
}