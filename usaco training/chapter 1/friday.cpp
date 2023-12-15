/*
ID: jacobse1
LANG: C++
TASK: friday
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n, m=0;
	fin >> n;
	vector<int> a(7, 0), t={3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
	for (int i = 1900; i < 1900+n; ++i) {
		for (int j = 0; j < 12; ++j) {
			a[m%7]++;
			(m+=t[j])%=7;
			if (j==1 && (i%400==0 || (i%100 && i%4==0))) (m+=1)%=7;
		}
	}

	for (int i = 0; i < 6; ++i) {
		fout << a[i] << ' ';
	} fout << a[6] << '\n';
	
	return 0;
}