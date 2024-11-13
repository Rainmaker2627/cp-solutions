#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n;
	vector<int> dp;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		auto t = lower_bound(dp.begin(), dp.end(), x);
		if (t==dp.end()) dp.push_back(x);
		else *t = x;
	}

	cout << dp.size() << '\n';
	return 0;
}