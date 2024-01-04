#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000

int n, m;
ll h[N], c[N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 0; i < m; ++i) cin >> c[i];

	for (int j = 0; j < m; ++j) {
		ll a=0;
		for (int i = 0; i < n; ++i) {
			if (a>=c[j]) break;
			if (h[i]<=a) continue;
			ll b=h[i];
			h[i]+=min(h[i], c[j])-a;
			a=b;
		}
	}

	for (int i = 0; i < n; ++i) cout << h[i] << '\n';
	return 0;
}