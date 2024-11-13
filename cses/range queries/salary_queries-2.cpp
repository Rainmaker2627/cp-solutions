#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int inf=1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	indexed_set s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert({a[i], i});
	}

	for (int i = 0; i < q; ++i) {
		char t;
		cin >> t;
		if (t=='!') {
			int k, x;
			cin >> k >> x;
			s.erase({a[--k], k});
			a[k]=x;
			s.insert({a[k], k});
		} else {
			int a, b;
			cin >> a >> b;
			cout << s.order_of_key({b, inf})-s.order_of_key({a-1, inf}) << '\n';
		}
	}

	return 0;
}