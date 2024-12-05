#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e9;

struct rect {
	int x1, x2, y1, y2;
	rect(int a, int b, int c, int d) {
		x1=a, y1=b, x2=c, y2=d;
	}
};

struct lazy {
	int n;
	unordered_map<int, int> cc;
	vector<int> ys, st, lz;

	lazy(vector<int>& y) {
		n=y.size();
		sort(y.begin(), y.end()); cc[y[0]]=1;
		ys.push_back(0);
		ys.push_back(y[0]);
		for (int i = 1, j = 1; i < n; ++i) {
			if (y[i]==y[i-1]) continue;
			ys.push_back(y[i]);
			cc[y[i]]=++j;
		}

		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		lz.assign(2*n, 0);
	}

	void update(int ql, int qr, int v, int n=1, int nl=1, int nr=1) {
		if (n==1) { ql=cc[ql]+1, qr=cc[qr]; nr=this->n; }
		if (qr<nl || nr<ql) return;
		if (ql<=nl && nr<=qr) {
			lz[n]+=v;
			if (lz[n]) st[n]=ys[nr]-ys[nl-1];
			else {
				if (nr==nl) st[n]=0;
				else st[n]=st[2*n]+st[2*n+1];
			} return;
		}
		update(ql, qr, v, 2*n, nl, (nl+nr)/2);
		update(ql, qr, v, 2*n+1, (nl+nr)/2+1, nr);
		if (lz[n]) st[n]=ys[nr]-ys[nl-1];
		else st[n]=st[2*n]+st[2*n+1];
	}

	int query() {
		return st[1];
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> y;
	vector<pair<int, int>> x;
	vector<rect> r;
	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rect t(x1, y1, x2, y2);
		y.push_back(y1);
		y.push_back(y2);
		x.push_back({x1, i});
		x.push_back({x2, -i});
		r.push_back(t);
	}

	sort(x.begin(), x.end());
	lazy st(y);

	int area=0, px=-inf;
	for (auto i : x) {
		int j=abs(i.second)-1, x=i.first;
		if (px<x) area=area+(x-px)*st.query(), px=x;
		st.update(r[j].y1, r[j].y2, (i.second<0?-1:1));
	} cout << area << '\n';

	return 0;
}