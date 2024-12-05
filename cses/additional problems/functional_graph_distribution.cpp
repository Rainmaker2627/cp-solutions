#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int exp(int a, int b, int m) {
	int x=1;
	while (b) {
		if (b&1) x=(x*a)%m;
		a=(a*a)%m;
		b>>=1;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> s(n+1, vector<int>()), c(n+1, vector<int>());
	s[0].push_back(1); c[0].push_back(1);
	for (int i = 1; i <= n; ++i) {
		s[i].push_back(-i*s[i-1][0]%mod);
		for (int j = 1; j < i; ++j) {
			s[i].push_back((s[i-1][j-1]-i*s[i-1][j]%mod)%mod);
		} s[i].push_back(1);

		c[i].push_back(1);
		for (int j = 1; j < i; ++j) {
			c[i].push_back((c[i-1][j-1]+c[i-1][j])%mod);
		} c[i].push_back(1);
	}

	for (int i = 1; i <= n; ++i) {
		int x=0, p=exp(n, n-1, mod), r=exp(n, mod-2, mod);
		for (int j = 0; j < n; ++j) {
			int t=(i-1<=j?abs(s[j][i-1]):0);
			x=(x+(c[n-1][j]*p%mod)*t%mod)%mod;
			p=(p*r)%mod;
		} cout << x << ' ';
	}

	return 0;
}