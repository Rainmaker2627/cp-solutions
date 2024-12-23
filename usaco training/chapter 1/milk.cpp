/*
ID: jacobse1
LANG: C++
TASK: milk
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m;
	fin >> n >> m;
	vector<pair<int, int>> v;
	for (int i = 0; i < m; ++i) {
		int p, a;
		fin >> p >> a;
		v.push_back({p, a});
	} sort(v.begin(), v.end());

	int c=0;
	for (auto [p, a] : v) {
		if (n>=a) { n-=a; c+=p*a; }
		else { c+=p*n; break; }
	}

	fout << c << '\n';
	return 0;
}