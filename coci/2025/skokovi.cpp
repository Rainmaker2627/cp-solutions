#include<bits/stdc++.h>
using namespace std;

vector<int> in, out;
set<pair<int, int>> e;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, a, b;
	cin >> n >> k;
	vector<int> f(n);

	cin >> f[0];
	cout << 1;
	a=b=f[0];

	for (int i = 1; i < n; ++i) {
		cin >> f[i];
		if (f[i]>a+k || f[i]<b-k) cout << ' ' << 0;
		else {
			if (f[i]>a) a=f[i];
			if (f[i]<b) b=f[i];
			cout << ' ' << 1;
		}
	} cout << '\n';

	return 0;
}