#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int exp(int a, int b, int m) {
	int x=1;
	while (b) {
		if (b%2) x=x*a%m;
		a=a*a%m; b/=2;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int m=1e6;
	vector<int> f(m+1, 1);
	for (int i = 2; i < m; ++i) {
		f[i]=i*f[i-1]%mod;
	}

	int n, r=1;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]/=2;
		if (i) {
			int b;
			if (a[i]<=a[i-1]) b=f[a[i-1]]*exp(f[a[i]]*f[a[i-1]-a[i]]%mod, mod-2, mod)%mod;
			else b=(f[a[i]-1])*exp(f[a[i-1]-1]*f[a[i]-a[i-1]]%mod, mod-2, mod)%mod;
			r=r*b%mod;
		}
	} cout << r << '\n';

	return 0;
}