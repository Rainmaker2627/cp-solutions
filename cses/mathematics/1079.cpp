#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
int n;

ll pow(ll a, ll b, int m) {
	ll p=1;
	while (b) {
		if (b%2) (p*=a)%=m;
		b/=2; (a*=a)%=m;
	}
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<ll> f(1000001); f[0]=1;
	for (int i = 1; i < 1000001; ++i) f[i]=(f[i-1]*i)%mod;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << f[a]*pow(f[b]*f[a-b]%mod, mod-2, mod)%mod << '\n';
	}

	return 0;
}