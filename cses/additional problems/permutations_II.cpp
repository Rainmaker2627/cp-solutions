#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	if (n<=1) { cout << 1 << '\n'; return 0; }
	if (n<=3) { cout << 0 << '\n'; return 0; }

	int a=1, b=1, c=0, d=0;
	for (int i = 4; i <= n; ++i) {
		int t=(((i+1)*d-(i-2)*c-(i-5)*b+(i-3)*a)%mod+mod)%mod;
		a=b, b=c, c=d, d=t;
	} cout << d << '\n';

	return 0;
}