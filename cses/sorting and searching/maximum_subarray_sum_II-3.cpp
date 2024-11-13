#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	multiset<int> s;
	vector<int> x(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i]; x[i] += x[i-1];
		if (a<=i && i<=b) s.insert(x[i]);
	}

	int m=-1e18;
	for (int i = 1; i <= n-a+1; ++i) {
		m=max(m, *prev(s.end())-x[i-1]);
		if (i+b<=n) s.insert(x[i+b]);
		s.erase(s.lower_bound(x[i+a-1]));
	} cout << m << '\n';

	return 0;
}