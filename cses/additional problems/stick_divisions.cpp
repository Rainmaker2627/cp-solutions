#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int x, n, r=0;
    cin >> x >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.push(-t);
    }

    while (pq.size()>1) {
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        r+=-a-b;
        pq.push(a+b);
    } cout << r << '\n';
    
    return 0;
}