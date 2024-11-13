#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> ppi;
typedef long long ll;
#define f first
#define s second

const int inf=1e9+7;

struct segtree {
	int n;
	bool f=false;
	vector<ll> st;
	unordered_map<int, int> c;

	segtree(int a, vector<int>& e) {
		sort(e.begin(), e.end());
		n=a; c[inf]=n; c[e[0]]=1;
		while ((n&(n-1))) n++;
		vector<ll> b(2*n, 0);
		swap(st, b);
		for (int i = 1, j = 2; i < e.size(); ++i, ++j) {
			while (e[i-1]==e[i]) i++;
			c[e[i]]=j;
		}
		for (int i = 0; i < e.size(); ++i) st[n+c[e[i]]-1]++;
		for (int i = n-1; i > 0; --i) st[i]=st[2*i]+st[2*i+1];
	}

	void print() {
		for (int i = 0; i < 2*n; ++i) {
			cout << st[i] << ' ';
		} cout << '\n';
	}

	ll query(int ql, int qr, int v=1, int nl=1, int nr=-1) {
		if (nr==-1) { 
			nr=this->n; qr=c[qr];
			if (f) ql=c[ql];
		}
		if (ql<=nl && qr>=nr) return st[v];
		else if (ql>nr || qr<nl) return 0;
		else return query(ql, qr, 2*v, nl, (nr+nl)/2) + query(ql, qr, 2*v+1, (nl+nr)/2+1, nr);
	}

	void update(int k, int v) {
		for (k=c[k]+n-1; k > 0; k/=2) st[k]+=v;
	}
};

bool fsort(ppi a, ppi b) {
	return (a.f.f==b.f.f?a.f.s>b.f.s:a.f.f<b.f.f);
}

int n;
vector<ppi> r;
vector<int> in, out, e;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e.push_back(b);
		r.push_back({{a, b}, i});
	} sort(r.begin(), r.end(), fsort);
	segtree st(n, e);

	in.reserve(n); out.reserve(n);
	for (int j = 0; j < n; ++j) {
		in[r[j].s]=st.query(1, r[j].f.s)-1;
		st.update(r[j].f.s, -1);
	} st.f=true;
	for (int j = 0; j < n; ++j) {
		out[r[j].s]=st.query(r[j].f.s, inf);
		st.update(r[j].f.s, 1);
	}

	for (int i = 0; i < n-1; ++i) {
		cout << in[i] << ' ';
	} cout << in[n-1] << '\n';
	for (int i = 0; i < n-1; ++i) {
		cout << out[i] << ' ';
	} cout << out[n-1] << '\n';

	return 0;
}