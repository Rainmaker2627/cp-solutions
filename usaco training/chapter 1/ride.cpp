/*
ID: jacobse1
LANG: C++
TASK: ride
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	int x=1, y=1;
	string a, b;
	fin >> a >> b;
	for (int i = 0; i < a.size(); ++i) x*=(a[i]-'A'+1);
	for (int i = 0; i < b.size(); ++i) y*=(b[i]-'A'+1);

	if (x%47 == y%47) fout << "GO\n";
	else fout << "STAY\n";

	return 0;
}