#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, m=0;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> k;
	set<int> s;
	vector<int> a(k), b(k), p(n+1, -1), u(n+1, 0), v(n+1, 0);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		p[a[i]]=i;
		s.insert(a[i]);
	} for (int i = 0; i < k; ++i) {
		cin >> b[i];
		if (p[b[i]]>-1) {
			m=max(m, ++u[(k+p[b[i]]-i)%k]);
			m=max(m, ++v[(k+p[b[i]]+i+1)%k]);
		}
		s.insert(b[i]);
	}

	cout << n-s.size()+m << '\n';
	return 0;
}