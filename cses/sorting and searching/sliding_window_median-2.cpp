#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	indexed_set s;
	vector<int> a(n);
	for (int i = 0; i < k-1; ++i) {
		cin >> a[i];
		s.insert({a[i], i});
	}

	for (int i = k-1, j = 0; i < n; ++i, j++) {
		cin >> a[i];
		s.insert({a[i], i});
		cout << (*s.find_by_order((k-1)/2)).first << " \n"[i==n-1];
		s.erase({a[j], j});
	}

	return 0;
}