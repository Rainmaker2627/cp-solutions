#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

int exp(int a, int b, int m) {
	int x=1;
	while (b) {
		if (b%2) x=(x*a)%m;
		a=(a*a)%m;
		b/=2;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;

	int h=0, b=0;
	for (auto i : s) {
		if (i=='(') h++;
		else h--;
		n--;
		if (h<0) { b=1; break; }
	}

	b|=(n-h)%2 | ((n-h)/2<0);
	if (b) {
		cout << 0 << '\n';
	} else {
		n=(n-h)/2;
		int a=1, b=1, c=1;
		for (int i = 2; i <= 2*n+h; ++i) {
			a=(a*i)%mod;
			if (i==n) b=a;
			if (i==n+h) c=a;
		} a=a*((h+1)*exp(n+h+1, mod-2, mod)%mod)%mod;
		cout << a*exp(b*c%mod, mod-2, mod)%mod << '\n';
	}

	return 0;
}