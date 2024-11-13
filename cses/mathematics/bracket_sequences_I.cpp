#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

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

	int n;
	cin >> n;

	if (n%2) {
		cout << 0 << '\n';
	} else {
		n/=2;
		int p=1, r;
		for (int i = 1; i <= 2*n; ++i) {
			if (i==n+1) r=exp(i*(p*p%mod)%mod, mod-2, mod);
			p=(p*i)%mod;
		} cout << p*r%mod << '\n';
	}
	

	return 0;
}