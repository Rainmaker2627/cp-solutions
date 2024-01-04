#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
 
int main(){
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;

		vector<ll> h(n), g(n), p(n);
		for (int i = 0; i < n; ++i) cin >> h[i];
		for (int i = 0; i < n; ++i) cin >> g[i];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			p[x]=i;
		}

		ll t = 0;
		for (int i = n - 2; i >= 0; i--) {
			ll x=(h[p[i+1]]+g[p[i+1]]*t)-(h[p[i]]+g[p[i]]*t);
			if (x >= 0) {
				ll y=g[p[i]]-g[p[i+1]];
				if (y <= 0) { t=-1; break; }
				t += 1+x/y;
			}
		}

		for (int i = n - 2; i >= 0; i--) {
			ll hi=h[p[i]]+g[p[i]]*t, lo=h[p[i+1]]+g[p[i+1]]*t;
			if (lo >= hi) { t = -1; break; }
		}

		cout << t << "\n";
	}
}