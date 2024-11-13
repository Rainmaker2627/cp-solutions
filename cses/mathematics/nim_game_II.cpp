#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int r=0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			r^=x;
		}

		cout << (r%4?"first":"second") << '\n';
	}

	return 0;
}