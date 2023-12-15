/*
ID: jacobse1
LANG: C++
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;

string n;
set<string> dict;
vector<string> a;
vector<vector<string>> c = {{"A", "B", "C"}, {"D", "E", "F"},
			{"G", "H", "I"}, {"J", "K", "L"}, {"M", "N", "O"},
			{"P", "R", "S"}, {"T", "U", "V"}, {"W", "X", "Y"}};

void gen(int t, string s) {
	if (t==n.size()) {
		if (dict.count(s)) a.push_back(s);
	} else {
		for (auto i : c[n[t]-'2']) {
			gen(t+1, s+i);
		}
	}
}

int main() {
	ifstream din("dict.txt");
	
	for (int i = 0; i < 4617; ++i) {
		string s;
		din >> s;
		dict.insert(s);
	}

	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	fin >> n;
	gen(0, "");

	if (a.size()) {
		for (int i = 0; i < a.size(); ++i) fout << a[i] << '\n';
	} else fout << "NONE\n";

	return 0;
}