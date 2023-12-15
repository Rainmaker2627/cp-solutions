/*
ID: jacobse1
LANG: C++
TASK: milk2
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int n;
	fin >> n;
	vector<pair<int, int>> t;
	for (int i = 0; i < n; ++i) {
		int a, b;
		fin >> a >> b;
		t.push_back({a, b});
	} sort(t.begin(), t.end());

	int a=t[0].second-t[0].first, b=0, c=t[0].first, d=t[0].second;
	for (int i = 1; i < n; ++i) {
		if (t[i].first > d) {
			a=max(a, d-c);
			b=max(b, t[i].first-d);
			c=t[i].first;
		} d=max(d, t[i].second);
	}

	fout << a << ' ' << b << '\n';
	return 0;
}