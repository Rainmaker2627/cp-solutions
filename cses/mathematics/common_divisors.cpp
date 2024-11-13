#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=1e6+1;
	cin >> n;
	vector<int> x(m, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		x[a]++;
	}

	for (int i = m; i > 0; --i) {
		int c=0;
		for (int j = i; j < m; j+=i) c+=x[j];
		if (c>1) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}