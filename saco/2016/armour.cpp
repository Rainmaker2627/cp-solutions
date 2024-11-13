#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	vector<int> v(n+1);
	cin >> v[1];
	for (int i = 2; i <= n; ++i) {
		cin >> v[i];
		v[i]+=v[i-1];
	}

	for (int i = 0; i < t; ++i) {
		int r=0, t, d;
		cin >> d;
		for (int i = d; i <= n; ++i) {
			if (v[i]-v[i-d]>r) t=i-d+1, r=v[i]-v[i-d];
		} cout << t << ' ' << r << '\n';
	}

	return 0;
}