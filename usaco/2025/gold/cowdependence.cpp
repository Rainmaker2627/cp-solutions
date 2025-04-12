#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<vector<int>> f;
int groups(int g, int x) {
    int l=f[g][0], r=1;
    for (auto i : f[g]) {
        if (i-l>x) l=i, r++;
    } return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    f.assign(n+1, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]].push_back(i);
    }
    
    int k=0;
    while (k*k<n) k++;
    vector<int> one(n+1, 0), two(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int m=f[i].size();
        if (m==0) continue;
        if (m<=k) {
            one[0]+=m+1;
            for (int j = 1; j <= m; j++) {
                int l=0, r=n+1;
                while (l<r) {
                    int mid=(l+r)/2;
                    if (groups(i, mid)<=j) r=mid;
                    else l=mid+1;
                } if (l<=n) one[l]--;
            }
        } else {
            vector<int> nxt(n, n);
            for (int j = n-2; j >= 0; j--) nxt[j]=(a[j+1]==i?j+1:nxt[j+1]);
            for (int j = 1; j <= n; j++) {
                int c=(a[0]==i?0:nxt[0]), r=0;
                while (c+j<n) c=nxt[c+j], r++;
                if (c<n) r++;
                two[j]+=r;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        one[i]+=one[i-1];
        cout << one[i]+two[i] << '\n';
    }

    return 0;
}