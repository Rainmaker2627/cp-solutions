#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<int> p(n+2, 0), q(n+2, 0);
	for (int i = 1; i < n+1; ++i) {
		cin >> p[i];
		q[p[i]]=i;
	} q[n+1]=1e9;

	int c=1;
	for (int i = 1; i <= n; ++i) c+=(q[i-1]>q[i]);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (p[a]>p[b]) swap(a, b);
		if (abs(p[a]-p[b])==1) c+=(q[p[a]-1]>b)+(b>a)+(a>q[p[b]+1])-((q[p[a]-1]>a)+(a>b)+(b>q[p[b]+1]));
		else c+=(q[p[a]-1]>b)+(b>q[p[a]+1])+(q[p[b]-1]>a)+(a>q[p[b]+1])-((q[p[a]-1]>a)+(a>q[p[a]+1])+(q[p[b]-1]>b)+(b>q[p[b]+1]));
		cout << c << '\n';
		swap(p[a], p[b]);
		swap(q[p[a]], q[p[b]]);
	}

	return 0;
}