#include<bits/stdc++.h>
using namespace std;

int conv(char a) { if (a==0) return -1; return a-(a>='a'?'a':'A'-26); }

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int ans = 0;

		map<int, int> m;
		for (int i = 0; i < 52; ++i) m[i]=-1;

		int p=1;
		set<char> s;
		vector<int> in(52, 0);
		for (int i = 0; i < a.length() && p; ++i) {
			s.insert(b[i]);
			int A=conv(a[i]), B=conv(b[i]);
			if (m[A]==-1) {
				m[A]=B;
				if (A!=B) { ans++; in[B]++; }
			} else if (m[A]!=B) p=0;
		}

		if (p && (s.size()<52 || s.size()==52 && a==b)) {
			vector<int> v(52, 0);
			for (int i = 0; i < 52; ++i) {
				if (v[i]==0) {
					int a=i, d=0;
					while (a!=-1 && v[a]==0) {
						v[a]=i+1; a=m[a];
						d=max(d, in[a]);
					} if (a==-1 || a==m[a]) continue;
					if (v[a]==i+1 && d==1) ans++;
				}
			} cout << ans << '\n';
		} else cout << -1 << '\n';
	}

	return 0;
}