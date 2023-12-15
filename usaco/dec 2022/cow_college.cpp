#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	} sort(c.begin(), c.end());

	ll m=0, t=0;
	for (int i = 0; i < n; ++i) {
		if (c[i]*(n-i)>m) {
			m=c[i]*(n-i);
			t=c[i];
		}
	}

	cout << m << ' ' << t << '\n';
	return 0;
}