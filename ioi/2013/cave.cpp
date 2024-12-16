#include "cave.h"
#include <bits/stdc++.h>
using namespace std;

void exploreCave(int N) {
	int s[N], d[N];
	vector<bool> vis(N, false);
	for(int i = 0; i < N; ++i) {
		int cor;
		vector<int> p;
		for(int j = 0; j < N; ++j) if (!vis[j]) p.push_back(j);
		for(int j = 0; j < N-i; ++j) s[p[j]] = 0;
		if (tryCombination(s)==i) cor=1;
		else cor=0;
		for(int j = 0; j < N-i; ++j) s[p[j]] = cor^1;

		int l=0, r=N-i-1;
		while (l<r) {
			int mid = (l+r)/2;
			for (int j = l; j <= mid; ++j) s[p[j]] = cor;
			int res = tryCombination(s);
			for (int j = l; j <= mid; ++j) s[p[j]] = cor^1;
			if (res==i) l=mid+1;
			else r=mid;
		} d[p[l]]=i; s[p[l]]=cor; vis[p[l]]=true;
	} answer(s, d);
}