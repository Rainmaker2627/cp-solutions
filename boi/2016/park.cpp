#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

struct dsu {
	int n;
	vector<int> r, s;

	dsu(int n) {
		this->n=n;
		r.reserve(n+1);
		for (int i = 0; i < n; ++i) r[i]=i;
		s.assign(n+1, 1);
	}

	int find(int a) {
		if (a==r[a]) return a;
		return r[a]=find(r[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return;
		if (s[a]<s[b]) swap(a, b);
		r[b]=a; s[a]+=s[b];
	}
};

struct visitor {
	int r, e, i;
	visitor(int a, int b, int c) { r=a, e=b, i=c; }
};

struct tree {
	int x, y, r, i;
	tree(int a) { x=y=r=0; i=a; }
	tree(int a, int b, int c, int d) { x=a, y=b, r=c, i=d; }
};

double dist(tree a, tree b) { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))-a.r-b.r; }
bool rcomp(visitor a, visitor b) { return a.r < b.r; }

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, w, h;
	cin >> n >> m >> w >> h;

	vector<tree> trees;
	for (int i = 0; i < n; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		trees.emplace_back(x, y, r, i);
	}

	int L=n, R=n+1, B=n+2, T=n+3;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n; ++i) {
		pq.push({trees[i].r-trees[i].x, {i, L}});
		pq.push({trees[i].x+trees[i].r-w, {i, R}});
		pq.push({trees[i].y+trees[i].r-h, {i, T}});
		pq.push({trees[i].r-trees[i].y, {i, B}});
		for (int j = i+1; j < n; ++j) {
			pq.push({-dist(trees[i], trees[j]), {i, j}});
		}
	}

	vector<visitor> visitors;
	for (int i = 0; i < m; ++i) {
		int r, e;
		cin >> r >> e;
		visitors.emplace_back(r, e, i);
	} sort(visitors.begin(), visitors.end(), rcomp);

	dsu uf(n+4);
	vector<int> ans(m, 0);
	for (int i = 0; i < m; ++i) {
		int r=visitors[i].r;
		while (-pq.top().first<2*r) {
			uf.unite(pq.top().second.first, pq.top().second.second);
			pq.pop();
		}
		int e=visitors[i].e, j=visitors[i].i;
		if (e==1) {
			if (uf.find(L)==uf.find(B)) ans[j]=1;
			else {
				ans[j]=15;
				if (uf.find(L)==uf.find(T) || uf.find(L)==uf.find(R)) ans[j]-=8;
				if (uf.find(T)==uf.find(R) || uf.find(L)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=4;
				if (uf.find(B)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=2;
			}
		} else if (e==2) {
			if (uf.find(R)==uf.find(B)) ans[j]=2;
			else {
				ans[j]=15;
				if (uf.find(T)==uf.find(R) || uf.find(L)==uf.find(R)) ans[j]-=4;
				if (uf.find(L)==uf.find(T) || uf.find(L)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=8;
				if (uf.find(B)==uf.find(L) || uf.find(B)==uf.find(T)) ans[j]-=1;
			}
		} else if (e==3) {
			if (uf.find(R)==uf.find(T)) ans[j]=4;
			else {
				ans[j]=15;
				if (uf.find(B)==uf.find(R) || uf.find(L)==uf.find(R)) ans[j]-=2;
				if (uf.find(B)==uf.find(L) || uf.find(L)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=1;
				if (uf.find(L)==uf.find(T) || uf.find(B)==uf.find(T)) ans[j]-=8;
			}
		} else {
			if (uf.find(L)==uf.find(T)) ans[j]=8;
			else {
				ans[j]=15;
				if (uf.find(L)==uf.find(B) || uf.find(L)==uf.find(R)) ans[j]-=1;
				if (uf.find(B)==uf.find(R) || uf.find(L)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=2;
				if (uf.find(T)==uf.find(R) || uf.find(B)==uf.find(T)) ans[j]-=4;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (ans[i]&(1<<j)) cout << j+1;
		} cout << '\n';
	}

	return 0;
}