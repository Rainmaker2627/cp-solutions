#include<bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
	int n;
	vector<int> r, s;

	dsu(int n) {
		this->n=n;
		r.reserve(n+1);
		for (int i = 1; i <= n; ++i) r[i]=i;
		s.assign(n+1, 1);
	}

	int find(int a) {
		if (a==r[a]) return a;
		return r[a]=find(r[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return;
		if (s[a]<s[b]) swap(a, b);
		r[b]=a; s[a]+=s[b];
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=0;
	cin >> n;
	vector<int> t;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		t.push_back(x);
		m=max(m, x);
	} sort(t.begin(), t.end());
	vector<int> s{t[0]};
	for (int i = 1; i < n; ++i) {
		if (t[i-1]!=t[i]) s.push_back(t[i]);
	} n=s.size();

	int j=1;
	unordered_map<int, int> r;
	vector<vector<pair<int, int>>> e(m+1, vector<pair<int, int>>());
	for (auto i = 0; i < s.size(); ++i, ++j) {
		r[s[i]]=i+1;
		int k=1, p=i+1;
		while (p<n) {
			k=s[p]/s[i]+1;
			if (s[p]%s[i]<s[0]) e[s[p]%s[i]].push_back({s[i], s[p]});
			p=lower_bound(s.begin(), s.end(), k*s[i])-s.begin();
		}
	}

	int ans=0;
	dsu uf(n);
	for (int i = 0; i <= m; ++i) {
		for (auto [u, v] : e[i]) {
			if (uf.find(r[u])==uf.find(r[v])) continue;
			uf.unite(r[u], r[v]);
			ans+=v%u;
		}
	} cout << ans << '\n';

	return 0;
}