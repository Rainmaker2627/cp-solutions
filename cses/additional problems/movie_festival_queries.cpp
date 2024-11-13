#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<pair<int, int>> m;

struct segtree {
	int n;
	vector<int> st;

	segtree(vector<int>& start, vector<int>& rev) {
		n=m.size();
		while (n&(n-1)) n++;
		st.assign(2*n, inf);
		for (int i = 0; i < m.size(); ++i) st[i+n]=rev[start[i]];
		for (int i = n-1; i > 0; --i) st[i]=min(st[2*i], st[2*i+1]);
	}

	int query(int a, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<a) return inf;
		if (nl>=a) return st[n];
		return min(query(a, 2*n, nl, (nl+nr)/2), query(a, 2*n+1, (nl+nr)/2+1, nr));
	}
};

bool compstart(int a, int b) { return m[a].first < m[b].first; }
bool compend(int a, int b) { return m[a].second < m[b].second; }
bool compsearch(int a, int b) { return m[a].first < b; }

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> start(n), end(n), rev(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		m.push_back({a, b});
		start[i]=end[i]=i;
	}

	sort(start.begin(), start.end(), compstart);
	sort(end.begin(), end.end(), compend);
	for (int i = 0; i < n; ++i) rev[end[i]]=i;
	segtree st(start, rev);

	int k=0;
	while (n>>k) k++;
	vector<vector<int>> bl(k+1, vector<int>(n+1, 0));
	for (int i = 0; i < n; ++i) {
		int s=st.query(lower_bound(start.begin(), start.end(), m[end[i]].second, compsearch)-start.begin()+1);
		bl[0][end[i]]=(s==inf?-1:end[s]);
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			int t=bl[i-1][j];
			if (t!=-1) t=bl[i-1][t];
			bl[i][j]=t;
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		int s=lower_bound(start.begin(), start.end(), a, compsearch)-start.begin();
		int c=end[st.query(s+1)], r=0;
		if (m[c].second<=b) r++;
		for (int i = k; i >= 0; --i) {
			int t=bl[i][c];
			if (t==-1 || m[bl[i][c]].second>b) continue;
			r+=1<<i, c=t;
		} cout << r << '\n';
	}

	return 0;
}