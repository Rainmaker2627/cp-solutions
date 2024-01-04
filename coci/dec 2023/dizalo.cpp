#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n, x;

struct segtree {
	int st[2*N]={0};
	int (*f)(int, int);

	segtree(int (*type)(int, int)) { f = type; }

	void update(int p, int v) {
		p+=n-1; st[p]=f(st[p], v);
		for (; p > 1; p/=2) st[p/2]=f(st[p], st[p^1]);
	}

	int query(int a, int b=-1) {
		if (b==-1) { swap(a, b); a=1; }
		int s=0; a+=n-1; b+=n-1;
		while (a<=b) {
			if (a%2==1) s=f(s, st[a++]);
			if (b%2==0) s=f(s, st[b--]);
			a/=2; b/=2;
		}
		return s;
	}
};

int add(int a, int b) { return a+b; }
int max(int a, int b) { return (a>b?a:b); }

segtree dv(add), dp(add), in(add), c(max);
int a[N], pos[N], q[N], e[N];
set<pair<int, int>> curr;
vector<int> sw[N];
bool act[N];

int calc(int x) {
	return x-dp.query(x)-a[x]+dv.query(a[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]]=i; e[i]=n+1;
	} for (int i = 1; i <= x; ++i) {
		cin >> q[i];
		e[a[q[i]]]=i;
	}

	for (int i = 1; i <= n; ++i) {
		int v = c.query(n+1-pos[i]);
		if (v<e[i]) {
			sw[v].push_back(pos[i]);
			sw[e[i]].push_back(-pos[i]);
			c.update(n+1-pos[i], e[i]);
		}
	}

	long long sol=0;
	for (int i = 0; i <= x; ++i) {
		if (i) {
			if (!act[q[i]]) {
				auto t = curr.lower_bound({a[q[i]], 0}); t--;
				sol -= in.query(t->second)-in.query(q[i]);
			}
			dv.update(a[q[i]], 1);
			dp.update(q[i], 1);
		}
		for (auto x : sw[i]) {
			if (x<0) {
				act[-x]=0;
				curr.erase({a[-x], -x});
				in.update(-x, -1);
				sol -= calc(-x);
			} else {
				act[x]=1;
				curr.insert({a[x], x});
				in.update(x, 1);
				sol += calc(x);
			}
		}
		cout << sol+n-i << ' ';
	}
	cout << '\n';

	return 0;
}