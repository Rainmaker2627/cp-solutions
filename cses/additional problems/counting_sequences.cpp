#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int exp(int a, int b, int m) {
	int x=1;
	while (b) {
		if (b&1) x=a*x%m;
		b>>=1; a=a*a%m;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int m=1e6+1;
	vector<int> f{1};
	for (int i = 1; i < m; ++i) {
		f.push_back(f[i-1]*i%mod);
	}

	int n, k, s=0;
	cin >> n >> k;
	for (int i = 0; i <= k; ++i) {
		int b=f[k]*exp(f[i]*f[k-i]%mod, mod-2, mod)%mod;
		s=(s+((k-i)%2?-1:1)*exp(i, n, mod)*b%mod+mod)%mod;
	} cout << s << '\n';

	return 0;
}