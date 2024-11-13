#include<bits/stdc++.h>
using namespace std;

struct rect {
	int x1, x2, y1, y2;
	rect(int a, int b, int c, int d) {
		x1=a, y1=b, x2=c, y2=d;
	}
};

struct lazy {
	int n;
	vector<int> st, lz;
	unordered_map<int, int> m;

	lazy(set<int>& s) {
		int i=1;
		for (auto j=s.begin(); j!=s.end(); j++) m[*j]=i++;
		n=i;
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		lz.assign(2*n, 0);
	}

	void push(int n, int l, int r) {
		st[n]+=(r-l+1)*lz[n];
		if (l<r) {
			lz[2*n]+=lz[n];
			lz[2*n+1]+=lz[n];
		} lz[n]=0;
	}

	void add(int v, int l, int r, int n=1, int nl=1, int nr=-1) {
		if (n==1) {
			l=m[l];
			r=m[r]-1;
			nr=this->n;
		}
		push(n, nl, nr);
		if (nr<l || nl>r) return;
		if (l<=nl && nr<=r) { lz[n]+=v; push(n, nl, nr); return; }
		st[n]+=(min(nr, r)-max(nl, l)+1)*v;
		add(v, l, r, 2*n, nl, (nl+nr)/2);
		add(v, l, r, 2*n+1, (nl+nr)/2+1, nr);
	}

	int sum(int l, int r, int n=1, int nl=1, int nr=-1) {
		if (n==1) {
			l=m[l];
			r=m[r]-1;
			nr=this->n;
		}
		push(n, nl, nr);
		if (l<=nl && nr<=r) return st[n];
		if (nr<l || nl>r) return 0;
		return sum(l, r, 2*n, nl, (nl+nr)/2)+sum(l, r, 2*n+1, (nl+nr)/2+1, nr);
	}

	void print() {
		for (int i = 0; i < 2*n; ++i) {
			if ((i&(i-1))==0) cout << "| ";
			cout << st[i] << ' ';
		} cout << '\n';
		for (int i = 0; i < 2*n; ++i) {
			if ((i&(i-1))==0) cout << "| ";
			cout << lz[i] << ' ';
		} cout << "\n\n";
	}
};

int main() {
	// cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	set<int> s;
	vector<pair<int, int>> xs;
	vector<rect> r;
	for (int i = 1; i <= n; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rect t(x1, y1, x2, y2);
		xs.push_back({x1, i});
		xs.push_back({x2, -i});
		r.push_back(t);
		s.insert(y1);
		s.insert(y2);
	}

	sort(xs.begin(), xs.end());
	lazy st(s);

	for (auto i : xs) {
		int j=abs(i.second)-1;
		if (i.second<0) {
			st.add(-1, r[j].y1, r[j].y2);
		} else {
			if (st.sum(r[j].y1, r[j].y2)) {
				cout << "JAH\n";
				cin >> n;
				return 0;
			} else st.add(1, r[j].y1, r[j].y2);
		}
	} cout << "EI\n";

	cin >> n;
	return 0;
}