#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
ll st[400000];

void update(int p, int v) {
	p+=n-1; st[p]=v;
	for (; p > 1; p/=2) st[p/2]=st[p]+st[p^1];
}

ll query(int a, int b) {
	ll s=0; a+=n-1; b+=n-1;
	while (a<=b) {
		if (a%2==1) s+=st[a++];
		if (b%2==0) s+=st[b--];
		a/=2; b/=2;
	}
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	for (int i = n; i < 2*n; ++i) cin >> st[i];
	for (int i = 2*n-1; i > 1; i-=2) st[i/2]=st[i]+st[i-1];

	for (int i = 0; i < q; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a==1) update(b, c);
		else cout << query(b, c) << '\n';
	}

	return 0;
}