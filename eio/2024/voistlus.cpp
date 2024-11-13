#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int mod=1e9+7;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	indexed_set s;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		s.insert(b[i]);
	} sort(b.begin(), b.end());

	for (int i = 0; i < n; ++i) {
		int r=0;
		for (int j = n-1; j >= 0; --j) {
			int t=1, p=0;
			s.erase(b[j]);
			for (int k = 0; k < n; ++k) {
				if (i==k) continue;
				t=(t*(s.order_of_key(a[i]+b[j]-a[k]+1)-p++))%mod;
			}
			r=(r+t)%mod;
			s.insert(b[j]);
			if (t==0) break;
		}
		cout << r%mod << '\n';
	}

	return 0;
}