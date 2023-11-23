#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	} sort(x.begin(), x.end());

	ll s=0;
	for (auto i : x) {
		if (i>s+1) break;
		else s+=i;
	}

	cout << s+1 << '\n';
	return 0;
}