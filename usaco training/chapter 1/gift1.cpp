/*
ID: jacobse1
LANG: C++
TASK: gift1
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int np;
	fin >> np;
	vector<string> n;
	map<string, int> m;
	for (int i = 0; i < np; ++i) {
		string s;
		fin >> s;
		n.push_back(s);
		m[s]=0;
	}

	for (int i = 0; i < np; ++i) {
		string s;
		int a, p;
		fin >> s >> a >> p;
		if (!p) continue;
		for (int i = 0; i < p; ++i) {
			string t;
			fin >> t;
			m[t]+=a/p;
		} m[s]+=-a+a%p;
	}

	for (int i = 0; i < np; ++i) {
		fout << n[i] << ' ' << m[n[i]] << '\n';
	}

	return 0;
}