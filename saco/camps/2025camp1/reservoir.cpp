#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	if (c>(n-1)*(n-2)/2) cout << -1 << '\n';
	else {
		vector<int> p{n}, u(n, 0);
		for (int i = 1; i < n-1; ++i) {
			if (n-1-i>=c) { p.push_back(n-1-c); u[n-1-c]=true; break; }
			else { p.push_back(i); c-=n-1-i; u[i]=true; }
		} if (!u[n-1]) p.push_back(n-1);

		for (int i = n-2; i > 0; --i) {
			if (u[i]) continue;
			p.push_back(i);
		}

		for (int i = 0; i < n; ++i) {
			cout << p[i] << ' ';
		}
	}

	return 0;
}