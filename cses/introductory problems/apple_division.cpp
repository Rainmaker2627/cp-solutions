#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s=0;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		s+=p[i];
	}

	int m=inf;
	for (int i = 0; i < (1<<n); ++i) {
		int c=0;
		for (int j = 0; j < n; ++j) {
			if (i&(1<<j)) c+=p[j];
		} m=min(m, abs(s-2*c));
	} cout << abs(m) << '\n';

	return 0;
}