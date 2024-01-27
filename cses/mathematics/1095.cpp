#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

ll pow(ll a, ll b, ll m) {
	ll r=1; a%=m;
	while (b) {
		if (b%2) r=(r*a)%m;
		a=(a*a)%m; b/=2;
	} return r;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		cout << pow(a, b, mod) << '\n';
	}

	return 0;
}