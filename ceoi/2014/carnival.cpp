#include<bits/stdc++.h>
using namespace std;
 
int query(vector<int>& q, int l, int r, int v=-1) {
    cout << r-l+1+(v>-1) << ' ';
    for (int i = l-1; i < r; i++) cout << q[i] << ' ';
    if (v>-1) cout << v;
    cout << endl;
    int x;
    cin >> x;
    return x;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, t=2;
    cin >> n;
    vector<int> ans(n+1, 0), rep{1}; ans[1]=1;
    for (int i = 2; i <= n; i++) {
        rep.push_back(i);
        if (query(rep, 1, t)<t) rep.pop_back();
        else ans[i]=t++;
    }
 
    for (int i = 2; i <= n; i++) {
        if (ans[i]) continue;
        int l=1, r=rep.size();
        while (l<r) {
            int mid=(l+r)/2;
            if (query(rep, l, mid, i)==mid-l+1) r=mid;
            else l=mid+1;
        } ans[i]=ans[rep[l-1]];
    }
    
    cout << 0 << ' ';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    } cout << endl;
    
    return 0;
}