#include "prize.h"
#include<bits/stdc++.h>
using namespace std;

bool visited[200000];
vector<int> res[200000];
int ans=-1, lol=0;

vector<int> query(int pos) {
    if (visited[pos]) return res[pos];
    visited[pos] = true;
    res[pos] = ask(pos);
    if (res[pos][0]+res[pos][1]==0) throw pos;
    return res[pos];
}

void search(int l, int r, int nl, int nr) {
    for (int i = 0; i < r-l+1; i++) {
        int mid, midl=(l+r)/2-i/2, midr=(l+r)/2+(i+1)/2;
        if (i%2) mid=midr;
        else mid=midl;
        auto x=query(mid);
        if (x[0]+x[1]==lol) {
            int xl=(i%2?midr-midl:0), xr=(i%2?0:midr-midl);
            if (x[0]-xl>nl) search(l, midl-1, nl, x[1]+xl);
            if (x[1]-xr>nr) search(midr+1, r, x[0]+xr, nr);
            break;
        }
    }
}

int find_best(int n) {
    try {
        int p=0;
        for (int i = 0; i < 474 && i < n && lol < 27; i++) {
            auto x=query(i);
            if (x[0]+x[1]>lol) p=i, lol=x[0]+x[1];
        } search(p, n-1, p, 0);
        return ans;
    } catch (int ans) {
        return ans;
    } return -1;
}