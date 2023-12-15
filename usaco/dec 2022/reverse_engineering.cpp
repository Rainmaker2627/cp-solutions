#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> in(m);
		vector<char> out(m);
		for (int i = 0; i < m; ++i) {
			cin >> in[i] >> out[i];
		}

		vector<bool> s(n, false);
		while (true) {
			bool f=false;
			for (int i = 0; i < n; ++i) {
				for (char v = '0'; v <= '1'; ++v) {
					for (char o = '0'; o <= '1'; ++o) {
						int a=1, b=0;
						for (int j = 0; j < m && a; ++j) {
							if (s[j]) continue;
							if (in[j][i]==v && out[j]==o) b++;
							else if (in[j][i]==v && out[j]!=o) a=0;
						}

						if (a&&b) {
							f=true;
							for (int j = 0; j < m; ++j) {
								if (in[j][i]==v) s[j]=true;
							}
						} if (f) break;
					} if (f) break;
				} if (f) break;
			} if (!f) break;
		}

		bool t=true;
		for (int i = 0; i < m && t; ++i) t&=s[i];
		if (t) cout << "OK\n";
		else cout << "LIE\n";
	}

	return 0;
}