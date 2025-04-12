#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    vector<int> in(n+1, 0), ra(n+1, -1), rb(n+1, -1);
    for (int i = 0; i < k; i++) {
        in[a[i]]++; in[b[i]]++;
        ra[a[i]]=rb[b[i]]=i;
    }

    int lcp=0;
    vector<int> off(k, 0), ofr(k, 0);
    for (int i = 0; i < k; i++) {
        if (ra[b[i]]==-1) continue;
        lcp=max(lcp, ++off[(k+i-ra[b[i]])%k]);
    } reverse(b.begin(), b.end());
    for (int i = 0; i < k; i++) {
        if (ra[b[i]]==-1) continue;
        lcp=max(lcp, ++ofr[(k+i-ra[b[i]])%k]);
    }
    
    int inz=0;
    for (int i = 1; i <= n; i++) {
        if (in[i]==0) inz++;
    } cout << lcp+inz << '\n';

    return 0;
}