#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int s=0, h;
		for (int i = 0; i < n; ++i) {
			cin >> h;
			s^=h;
		} cout << (s==0?"second":"first") << '\n';
	}

	return 0;
}