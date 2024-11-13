#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int sum(int l, int r) {
	int t=0;
	t+=((((r%mod)*((r+1)%mod))%mod)*500000004)%mod;
	t-=((((l%mod)*((l+1)%mod))%mod)*500000004)%mod;
	return (t+mod)%mod;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	int s=0, i=1;
	for (; i*i <= n; ++i) {
		s+=i*(n/i);
		s%=mod;
	}

	int l=--i, r;
	for (; i > 0; --i) {
		r=n/i;
		s=(s+i*sum(l, r))%mod;
		l=r;
	}

	cout << s << '\n';
	return 0;
}