#include<bits/stdc++.h>
using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << min(a, b) << ' ' << max(a, b) << '\n';
	}

	return 0;
}