#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll c[1000000], t[1000000];

bool check(ll v) {
	ll p=0;
	for (int i = 0; i < n; ++i) {
		if (c[i]<t[p]-v) return false;
		else if (c[i]>t[p]+v) {
			while (p<m && c[i]>t[p]+v) p++;
			if (c[i]<t[p]-v || p==m) return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = 0; i < m; ++i) cin >> t[i];

	ll lo=0, hi=2e9+1;
	while (lo<hi) {
		ll mid = (hi+lo)/2;
		if (check(mid)) {
			hi=mid;
		} else {
			lo=mid+1;
		}
	}
	cout << lo << '\n';
	return 0;
}