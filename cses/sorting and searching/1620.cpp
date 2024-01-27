#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, t;
	cin >> n >> t;

	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}

	ll lo=0, hi=1e18+1, s;
	while (lo<hi) {
		ll mid=(lo+hi)/2; s=0;
		for (auto i : k) {
			if ((s+=mid/i)>=t) { 
				hi=mid;
				break;
			}
		}
		if (s<t) lo=mid+1;
	}

	cout << hi << '\n';
	return 0;
}