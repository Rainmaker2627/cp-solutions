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
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << exp(a, b, mod) << '\n';
	}

	return 0;
}