#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int t=0;
		vector<char> a(n, '.');
		set<int> g, h;
		for (int i = 0; i < n; ++i) {
			if (s[i]=='H') {
				if (h.empty() || *(--h.end())<i-k) {
					int j=min(i+k, n-1); t++;
					if (a[j]=='G') j--;
					a[j]='H';
					h.insert(j);
				}
			} else {
				if (g.empty() || *(--g.end())<i-k) {
					int j=min(i+k, n-1); t++;
					if (a[j]=='H') j--;
					a[j]='G';
					g.insert(j);
				}
			}
		}

		cout << t << '\n';
		for (auto i : a) {
			cout << i;
		} cout << '\n';
	}
	
	return 0;
}