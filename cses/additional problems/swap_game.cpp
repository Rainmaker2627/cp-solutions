#include<bits/stdc++.h>
using namespace std;

vector<int> p={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int swap(int i, int j, int s) {
	int a=(s/p[i])%10, b=(s/p[j])%10;
	return s+(a-b)*(p[j]-p[i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	unordered_map<int, int> m, v;
	int s=123456789;
	m[s]=0;

	int r=0;
	for (int i = 0; i < 9; ++i) {
		int x;
		cin >> x;
		r=10*r+x;
	}

	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int s=q.front();
		q.pop();
		if (v.count(s)) continue;
		else v[s]=1;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				int a=swap(3*i+j,3*i+j+1,s), b=swap(i+3*j,i+3*j+3,s);
				if (!m.count(a)) { m[a]=m[s]+1; q.push(a); }
				if (!m.count(b)) { m[b]=m[s]+1; q.push(b); }
			}
		}
	}

	cout << m[r] << '\n';

	return 0;
}