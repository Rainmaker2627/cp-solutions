#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100000;
const int MAXC=1000000000;

struct dsu {
	int n, c;
	vector<int> p, s;

	dsu(int n) {
		this->n=n; c=n;
		p.reserve(n+1); s.assign(n+1, 1);
		for (int i = 1; i <= n; ++i) p[i]=i;
	}

	int find(int a) {
		if (a==p[a]) return a;
		return p[a]=find(p[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (s[a]<s[b]) swap(a, b);
		p[b]=a; s[a]+=s[b];
	}
};

struct road {
	int a, b, r, d;
	road(int w, int x, int y, int z) { a=w, b=x, r=y, d=z; }
};

int randint(int a, int b) {
	int n=rand()*(RAND_MAX+1)+rand();
	return n%(b-a+1)+a;
}

signed main() {
	ofstream cout("test.txt");
	srand((unsigned) time(0));

	int n=randint(2, MAXN);
	int m=randint(n-1, min((int)2*MAXN, n*(n-1)/2));
	int p=randint(1, n);
	int c=randint(1, MAXC);

	vector<int> p_arr;
	set<int> p_set;
	for (int i = 0; i < p; ++i) {
		int t=randint(1, n);
		while (p_set.count(t)) t=randint(1, n);
		p_set.insert(t);
		p_arr.push_back(t);
	}

	dsu uf(n);
	vector<road> roads;
	set<pair<int, int>> s;
	for (int i = 0; i < n-1; ++i) {
		int a=randint(1, n), b=randint(1, n);
		while (uf.find(a)==uf.find(b)) a=randint(1, n), b=randint(1, n);
		uf.unite(a, b);
		int r=randint(1, MAXC), d=randint(1, MAXC);
		roads.emplace_back(a, b, r, d);
		s.insert({min(a, b), max(a, b)});
	}

	for (int i = n-1; i < m; ++i) {
		int a=randint(1, n), b=randint(1, n), r=randint(1, MAXC), d=randint(1, MAXC);
		while (a==b || s.count({min(a, b), max(a, b)})) a=randint(1, n), b=randint(1, n);
		roads.emplace_back(a, b, r, d);
		s.insert({min(a, b), max(a, b)});
	}

	int seed=chrono::system_clock::now().time_since_epoch().count();
	shuffle(roads.begin(), roads.end(), default_random_engine(seed));

	cout << n << ' ' << m << ' ' << p << ' ' << c << '\n';
	cout << p_arr[0];
	for (int i = 1; i < p; ++i) cout << ' ' << p_arr[i];
	cout << '\n';
	for (int i = 0; i < m; ++i) {
		cout << roads[i].a << ' ' << roads[i].b << ' ' << roads[i].d << ' ' << roads[i].r << '\n';
	}

	return 0;
}