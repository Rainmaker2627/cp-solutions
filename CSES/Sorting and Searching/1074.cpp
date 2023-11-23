#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	} sort(p.begin(), p.end());

	ll m=(n%2?p[n/2]:(p[n/2-1]+p[n/2])/2), s=0;
	for (auto i : p) s+=abs(i-m);

	cout << s << '\n';
	return 0;
}