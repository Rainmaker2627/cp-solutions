#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll m=-1e9, c=0, x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		c+=x;
		m=max(c,m);
		if (c<0) c=0;
	}

	cout << m << '\n';
	return 0;
}