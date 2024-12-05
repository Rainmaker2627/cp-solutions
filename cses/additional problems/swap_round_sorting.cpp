#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		x[i]--;
	}

	int m=0;
	vector<bool> s(n, false);
	vector<pair<int, int>> a, b;
	for (int i = 0, j = 0; i < n; ++i, j=i) {
		if (s[i]) continue;
		vector<int> c;
		while (s[j]==0) {
			c.push_back(j);
			s[j]=true;
			j=x[j];
		}

		int n=c.size();
		if (n>2) { m=2;
			for (int l = 1, r = n-1; l < r; ++l, --r) {
				a.push_back({c[l]+1, c[r]+1});
				swap(c[l], c[r]);
				swap(x[c[l]], x[c[r]]);
			}

			for (int i = 0; i < n; ++i) {
				if (c[i]==x[c[i]]) continue;
				b.push_back({c[i]+1, x[c[i]]+1});
				swap(x[x[c[i]]], x[c[i]]);
			}
		} else if (n>1) { m=max(m, 1);
			a.push_back({c[0]+1, c[1]+1});
		}
	}

	cout << m << '\n';
	if (m>=1) {
		cout << a.size() << '\n';
		for (auto [u, v] : a) {
			cout << u << ' ' << v << '\n';
		}
	} if (m==2) {
		cout << b.size() << '\n';
		for (auto [u, v] : b) {
			cout << u << ' ' << v << '\n';
		}
	}

	return 0;
}