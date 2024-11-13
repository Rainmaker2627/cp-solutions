#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
int n, t;

struct matrix {
	ll a, b, c, d;

	matrix(ll p, ll q, ll r, ll s) {
		a=p; b=q; c=r; d=s;
	}

	void operator*=(matrix m) {
		ll p=(a*m.a+b*m.c)%mod, q=(a*m.b+b*m.d)%mod, r=(c*m.a+d*m.c)%mod, s=(c*m.b+d*m.d)%mod;
		a=p; b=q; c=r; d=s;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> t;
	while (t--) {
		matrix id(1, 0, 0, 1);
		matrix m(4, 1, 1, 2);

		cin >> n; n--;
		while (n) {
			if (n%2) id*=m;
			m*=m; n/=2;
		}
		cout << (id.a+id.b+id.c+id.d)%mod << '\n';
	}

	return 0;
}
