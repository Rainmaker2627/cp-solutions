#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	ll n;
	cin >> n;
	bool p=true;
	for (ll a = 2; a <= ll(sqrt(n))+1 && p; ++a) {
		if (2*n%a) continue;
		ll b = 2*n/a;
		if ((a+b)%2 && (b-a)%2) {
			ll T=(a+b-1)/2, S=(b-a+1)/2;
			if (T<0 || S<0) continue;
			cout << S << ' ' << T << '\n';
			p=false;
		}
	}

	if (p) cout << -1 << '\n';

	return 0;
}