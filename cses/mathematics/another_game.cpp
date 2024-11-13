#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int x, b=0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			b|=(x&1);
		} cout << (b?"first":"second") << '\n';
	}

	return 0;
}