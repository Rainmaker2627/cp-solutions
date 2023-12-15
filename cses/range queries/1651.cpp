#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000

int n, q;
ll c[N], st[2*N+1];

ll query(int a, int b) {
	a+=n-1; b+=n-1;
	ll s=0;
	while (a<=b) {
		if (a%2==1) s+=st[a++];
		if (b%2==0) s+=st[b--];
		a/=2; b/=2;
	} return s;
}

void update(int p, int v) {
	p+=n-1; st[p]+=v;
	while (p>1) { st[p/2]=st[p]+st[p^1]; p/=2; }
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> c[i];

	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t==2) {
			int k;
			cin >> k;
			cout << c[k-1] + query(1, k) << '\n';
		} else {
			int a, b, u;
			cin >> a >> b >> u;
			update(a, u);
			if (b<n) update(b+1, -u);
		}
	}

	return 0;
}