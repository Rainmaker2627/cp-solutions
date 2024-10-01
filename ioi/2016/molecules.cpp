#include "molecules.h"
#include<bits/stdc++.h>
using namespace std;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
	long long s=0, lo=0, hi=0, n=w.size();
	vector<pair<int, int>> t;
	vector<int> ans(0);
	for (int i = 0; i < n; ++i) t.emplace_back(w[i], i);
	sort(t.begin(), t.end());
	while (lo<n) {
		if (s<l) {
			if (hi<n) s+=t[hi++].first;
			else break;
		} else if (s>u && lo<n) s-=t[lo++].first;
		if (l<=s && s<=u) {
			for (int i = lo; i < hi; ++i) ans.push_back(t[i].second);
			break;
		}
	} return ans;
}