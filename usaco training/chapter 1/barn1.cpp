/*
ID: jacobse1
LANG: C++
TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int m, s, c;
	fin >> m >> s >> c;
	vector<int> p(c), d;
	for (int i = 0; i < c; ++i) {
		fin >> p[i];
	} sort(p.begin(), p.end());

	for (int i = 1; i < c; ++i) {
		d.push_back(p[i]-p[i-1]-1);	
	} sort(d.begin(), d.end());

	int l=c;
	for (int i = 0; i < c-m; ++i) l+=d[i];

	fout << l << '\n';
	return 0;
}