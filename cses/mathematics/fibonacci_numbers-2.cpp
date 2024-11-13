#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

struct matrix {
	int a, b, c, d;

	matrix(int p, int q, int r, int s) {
		a=p; b=q; c=r; d=s;
	}

	void operator*=(matrix m) {
		int p=(a*m.a+b*m.c)%mod, q=(a*m.b+b*m.d)%mod, r=(c*m.a+d*m.c)%mod, s=(c*m.b+d*m.d)%mod;
		a=p; b=q; c=r; d=s;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	if (n==0) {
		cout << 0 << '\n';
	} else {
		n--;
		matrix id(1, 0, 0, 1);
		matrix m(1, 1, 1, 0);
		while (n) {
			if (n%2) id*=m;
			m*=m; n/=2;
		} cout << id.a%mod << '\n';
	}

	return 0;
}