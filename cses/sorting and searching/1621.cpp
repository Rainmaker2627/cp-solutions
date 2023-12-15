#include<bits/stdc++.h>
using namespace std;

int n;
set<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int b, c=0;
	for (int i = 0; i < n; ++i) {
		cin >> b;
		if (x.count(b)) continue;
		c++;
		x.insert(b);
	}

	cout << c << '\n';
	return 0;
}