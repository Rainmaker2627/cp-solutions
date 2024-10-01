#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, int> m;
	vector<int> c(n, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (m.count(a)) {
			c[i]=m[a];
			if (c[m[a]]==-1 || i-m[a]<m[a]-c[m[a]]) c[m[a]]=i;
		} else c[i]=-1;
		m[a]=i;
	}

	for (int i = 0; i < n; ++i) {
		if (c[i]==-1) cout << -1 << ' ';
		else cout << abs(c[i]-i) << ' ';
	}

	return 0;
}