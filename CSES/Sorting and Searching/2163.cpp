#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n, k;

int main() {
	cout.tie(0)->sync_with_stdio(false);

	cin >> n >> k;
	ordered_set s;
	for (int i = 0; i < n; ++i) {
		s.insert(i+1);
	}

	int p=0;
	while (n>1) {
		p=(p+k)%n--;
		auto t = s.find_by_order(p);
		cout << *t << ' ';
		s.erase(t);
	} cout << *s.begin() << '\n';

	return 0;
}