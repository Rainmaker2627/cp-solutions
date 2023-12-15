#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a;
set<int> b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	int j=-1, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (b.count(x-t)) { j=i; break; }
		b.insert(t); a.push_back(t);
	}

	if (j>-1) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i]==x-t) {
				cout << i+1 << ' ' << j+1 << '\n';
			}
		}
	} else cout << "IMPOSSIBLE\n";
	
	
	return 0;
}