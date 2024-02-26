#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

struct lazy {
	int n;
	vector<int> st, lz;

	lazy(int a, vector<int>& arr) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 0), c(2*n, 0);
		for (int i = n; i < n+a; ++i) { cin >> arr[i-n+1]; b[i]=b[i-1]+arr[i-n+1]; }
		for (int i = n-1; i > 0; --i) b[i]=max(b[2*i], b[2*i+1]);
		swap(lz, c); swap(st, b);
	}

	void push(int n, int l, int r) {
		st[n]+=lz[n];
		if (l!=r) {
			lz[2*n]+=lz[n];
			lz[2*n+1]+=lz[n];
		} lz[n]=0;
	}

	void update(int a, int b, int v, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || l>b) return;
		if (a<=l && r<=b) { lz[n]=v; push(n, l, r); return; }
		update(a, b, v, 2*n, l, (l+r)/2);
		update(a, b, v, 2*n+1, (l+r)/2+1, r);
		st[n]=max(st[2*n], st[2*n+1]);
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) {
			r=this->n;
			if (a<1) return 0;
		} push(n, l, r);
		if (r<a || l>b) return -inf;
		if (a<=l && r<=b) return st[n];
		return max(query(a, b, 2*n, l, (l+r)/2), query(a, b, 2*n+1, (l+r)/2+1, r));
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q, t, a, b;
	cin >> n >> q;
	vector<int> arr(n+1);
	lazy st(n, arr);
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		if (t==1) { st.update(a, n, b-arr[a]); arr[a]=b; }
		else cout << max(st.query(a, b)-st.query(a-1, a-1), (long long) 0) << '\n';
	}

	return 0;
}
