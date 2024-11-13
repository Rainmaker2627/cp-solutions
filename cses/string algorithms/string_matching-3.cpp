#include<bits/stdc++.h>
using namespace std;
#define int long long

string s, p;
vector<int> mat;

void testmat(int prime, int mod, int inv) {
	int sh=0, ph=0, cur=1;
	for (int i = 0; i < p.length(); ++i) {
		sh=(sh+(s[i]-'a'+1)*cur)%mod;
		ph=(ph+(p[i]-'a'+1)*cur)%mod;
		cur=(cur*prime)%mod;
	} mat[p.length()-1]+=(sh==ph);
	for (int i = p.length(), j = 0; i < s.length(); ++i, ++j) {
		sh=((sh-(s[j]-'a'+1)+cur*(s[i]-'a'+1))*inv)%mod;
		mat[i]+=(sh==ph);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> s >> p;

	if (p.length()>s.length()) {
		cout << 0 << '\n';
	} else {
		mat.assign(s.length(), 0);
		testmat(31, 1e9+7, 129032259);
		testmat(47, 1e9+9, 340425535);
		testmat(53, 998244353, 828731161);

		int s=0;
		for (auto i : mat) {
			if (i==3) s++;
		} cout << s << '\n';

		int x=0;
	}

	return 0;
}