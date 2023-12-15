#include<bits/stdc++.h>
using namespace std;

int n, q;
long long x[200001];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		x[i]^=x[i-1];
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << (x[b]^x[a-1]) << '\n';
	}

	return 0;
}