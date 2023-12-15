#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
ll n;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	vector<int> bin;
	while (n) {
		bin.push_back(n&1);
		n>>=1;
	}

	ll t=0, a=0, b=1;
	for (int i = bin.size()-2; i >= 0;--i) {
		t=a, a=(a*a%mod+b*b%mod)%mod, b=(b*(2*t+b))%mod;
		if (bin[i]==1) {
			t=a, a=b, b=(t+b)%mod;
		}
	}

	cout << (bin.size()==0?0:b) << '\n';
	return 0;
}