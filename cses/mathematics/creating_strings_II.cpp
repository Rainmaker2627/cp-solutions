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

	int m=1e6+1;
	vector<int> f(m, 1);
	for (int i = 2; i < m; ++i) f[i]=i*f[i-1]%mod;

	string s;
	cin >> s;
	int n=s.size();
	vector c(26, 0);
	for (int i = 0; i < n; ++i) c[s[i]-'a']++;

	int x=f[s.size()], r=1;
	for (int i = 0; i < 26; ++i) r=(r*f[c[i]])%mod;
	cout << x*exp(r, mod-2, mod)%mod << '\n';

	return 0;
}