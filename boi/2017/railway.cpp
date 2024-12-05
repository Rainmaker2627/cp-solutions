#include<bits/stdc++.h>
using namespace std;

vector<int> dep, pos, par, val, eul;
vector<vector<int>> adj;

struct sparse {
	int n, m;
	vector<vector<int>> sp;

	int high(int a, int b) {
		return (dep[a]<=dep[b]?a:b);
	}

	void build() {
		m=0; n=eul.size();
		while ((1<<m)<n) m++;
		sp.assign(m, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) sp[0][i]=eul[i];
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n-(1<<i)+1; ++j) {
				sp[i][j]=high(sp[i-1][j], sp[i-1][j+(1<<i-1)]);
			}
		}
	}

	int query(int a, int b) {
		if (a==b) return a;
		a=pos[a], b=pos[b];
		if (a>b) swap(a, b);
		int d=b-a, t=0;
		while ((1<<t)<=d) t++; t--;
		return high(sp[t][a], sp[t][b-(1<<t)+1]);
	}
} sp;

bool pcomp(int a, int b) { return pos[a]<pos[b]; }
void dvts(vector<int>& ic) {
	int n=ic.size();
	sort(ic.begin(), ic.end(), pcomp);
	val[ic[0]]++; val[sp.query(ic[0], ic[n-1])]--;
	for (int i = 1; i < n; ++i) {
		val[ic[i]]++;
		val[sp.query(ic[i], ic[i-1])]--;
	}
}

void tour(int u, int p) {
	par[u]=p;
	dep[u]=dep[p]+1;
	pos[u]=eul.size();
	eul.push_back(u);
	for (auto v : adj[u]) {
		if (v==p) continue;
		tour(v, u);
		eul.push_back(u);
	}
}

void fill(int u, int p) {
	for (auto v : adj[u]) {
		if (v==p) continue;
		fill(v, u);
		val[u]+=val[v];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int, int>, int> eord;
	adj.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (a<b) swap(a, b);
		eord[{a, b}]=i+1;
	}

	pos.assign(n+1, 0);
	dep.assign(n+1, 0);
	par.assign(n+1, 0);
	tour(1, 1);
	sp.build();

	val.assign(n+1, 0);
	for (int i = 0, s; i < m; ++i) {
		cin >> s;
		vector<int> c(s);
		for (int i = 0; i < s; ++i) {
			cin >> c[i];
		} dvts(c);
	} fill(1, 1);

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (val[i]<k) continue;
		int a=i, b=par[i];
		if (a<b) swap(a, b);
		ans.push_back(eord[{a, b}]);
	} sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	} cout << '\n';

	return 0;
}