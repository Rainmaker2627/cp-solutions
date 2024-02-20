#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int main() {
	// cin.tie(0)->sync_with_stdio(false);

	ll n;
	cin >> n;

	ll s=0, r=(ll)sqrt(n);
	for (int i = 2; i <= r; ++i) {
		s=(s+i*(n/i))%mod;
	} s=s+((n%mod)*(n%mod+1)/2)%mod;


	cout << s%mod << '\n';
	cin >> n;
	return 0;
}