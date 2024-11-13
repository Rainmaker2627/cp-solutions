#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b, a%b);
}

int exp(int a, int b, int m) {
	int x=1;
	while (b) {
		if (b%2) x=(x*a)%m;
		a=(a*a)%m;
		b/=2;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int s=0;
	for (int i = 1; i <= n; ++i) {
		s=(s+exp(m, gcd(i, n), mod))%mod;
	} cout << s*exp(n, mod-2, mod)%mod << '\n';

	return 0;
}