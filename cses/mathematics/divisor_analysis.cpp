#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int power(int a, int b, int m=mod) {
	int r=1; a%=m; b%=m-1;
	while (b) {
		if (b%2) r=r*a%m;
		a=a*a%m; b/=2;
	} return r;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x, k, d=1, s=1, p=1, t=1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> k;
		d=d*(k+1)%mod;
		s=s*((power(x, k+1)-1)*power(x-1, mod-2)%mod)%mod;
		p=power(p, k+1)*power(power(x, k*(k+1)/2), t)%mod;
		t=t*(k+1)%(mod-1);
	}

	cout << d << ' ' << s << ' ' << p << '\n';
	return 0;
}