#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x=0;
	cin >> n;
	for (int i = 0, t; i < n; ++i) {
		cin >> t;
		if (~(n-1)&i) continue;
		x^=t;
	} cout << x << '\n';

	return 0;
}