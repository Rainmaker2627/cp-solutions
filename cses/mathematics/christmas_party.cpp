#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	
	int d=0;
	for (int i = 2; i <= n; ++i) {
		d=(i*d+(i%2?-1:1))%mod;
	} cout << d << '\n';

	return 0;
}