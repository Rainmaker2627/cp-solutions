#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int exp(int a, int b, int m) {
	int x=1; b%=mod-1;
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
		int s=n/2*(n/2+1);
		int r=(exp(2, 4*s, mod)+exp(2, 2*s, mod)+2*exp(2, s, mod))%mod;
		cout << r*exp(2, mod-2, mod)%mod << '\n';
	} else {
		int s=n*n;
		int r=(exp(2, s, mod)+exp(2, s/2, mod)+2*exp(2, s/4, mod))%mod;
		cout << r*exp(4, mod-2, mod)%mod << '\n';
	}

	return 0;
}