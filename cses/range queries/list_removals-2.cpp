#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	indexed_set s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(i);
	}

	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		auto t = s.find_by_order(k-1);
		cout << a[*t] << ' ';
		s.erase(t);
	}

	return 0;
}