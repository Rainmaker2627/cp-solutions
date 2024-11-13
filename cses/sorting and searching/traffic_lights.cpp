#include<bits/stdc++.h>
using namespace std;

int x, n;
int dsu[200002], s[200002];

int find(int a) {
	while (a!=dsu[a]) { dsu[a]=dsu[dsu[a]]; a=dsu[a]; }
	return a;
}

void unite(int a, int b) {
	a=find(a);
	b=find(b);
	if (s[a]<s[b]) swap(a,b);
	s[a]+=s[b];
	dsu[b]=a;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> x >> n;
	vector<int> q(n);
	vector<pair<int, int>> p;
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
		p.push_back({q[i], i});
	} sort(p.begin(), p.end());

	dsu[0]=0; dsu[n]=n;
	s[0]=p[0].first; s[n]=x-p[n-1].first;
	int m=max(s[0], s[n]);
	q[p[0].second]=0;
	for (int i = 1; i < n; ++i) {
		q[p[i].second]=i;
		dsu[i]=i;
		s[i]=p[i].first-p[i-1].first;
		m=max(m, s[i]);
	}

	stack<int> a;
	a.push(m);
	for (int i = n-1; i > 0; --i) {
		unite(q[i], q[i]+1);
		m=max(m, s[find(q[i])]);
		a.push(m);
	}

	while(a.size()>1) {
		cout << a.top() << ' ';
		a.pop();
	}
	cout << a.top() << '\n';
	return 0;
}