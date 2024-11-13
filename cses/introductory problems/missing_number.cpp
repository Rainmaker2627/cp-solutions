#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> test(n-1), find(n, 1);
	for (int i = 0; i < n-1; ++i) {
		cin >> test[i];
	}

	for (int i = 0; i < n-1; ++i) {
		find[test[i]-1]=0;
	}

	for (int i = 0; i < n; ++i) {
		if (find[i]==1) cout << i+1 << '\n';
	}

	return 0;
}