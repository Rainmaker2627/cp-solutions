#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> h;
bool gradcomp(int i, int j, int k) {
	return (h[j]-h[i])*abs(k-i)<=(h[k]-h[i])*abs(j-i);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	h.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) cin >> h[i];

	int a=0;
	vector<set<int>> v(n+1, set<int>());
	for (int i = 1; i < n; ++i) {
		auto &s=v[i];
		s.insert(i+1);
		for (int j = i+2, p = i+1; j <= n; ++j) {
			if (gradcomp(i, p, j)) s.insert(p=j);
		} a+=s.size();
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		h[x]+=y;
		for (int j = 1; j <= x-1; ++j) {
			auto &s=v[j]; a-=s.size();
			auto p=s.lower_bound(x);
			bool in=false;
			if ((*p)==x) in=true, p++;
			else if (gradcomp(j, *(--p), x)) {
				s.insert(x);
				p=next(next(p));
				in=true;
			}

			if (in) {
				while (p!=s.end() && !gradcomp(j, x, *p)) p=s.erase(p);
			} a+=s.size();
		}

		auto &s=v[x];
		a-=s.size();
		s.clear();
		if (x<n) s.insert(x+1);
		for (int j = x+2, p = x+1; j <= n; ++j) {
			if (gradcomp(x, p, j)) s.insert(p=j);
		} a+=s.size();
		cout << a << '\n';
	}

	return 0;
}