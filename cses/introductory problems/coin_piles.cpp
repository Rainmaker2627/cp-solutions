#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int s=(a+b)/3;
		if ((a+b)%3 || a<s || b<s) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}