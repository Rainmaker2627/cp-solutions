#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            r[i][j]=(c=='.');
        }

        for (int j = m-1; j >= 1; j--) {
            if (r[i][j]) r[i][j]+=r[i][j+1];
        }
    }

    vector<vector<int>> u(n+1, vector<int>(m+1)), d(n+1, vector<int>(m+1));
    for (int j = 1; j <= m; ++j) {
        vector<int> a;
        for (int i = 1; i <= n; ++i) {
            while (!a.empty() && r[i][j]<r[a.back()][j]) a.pop_back();
            u[i][j]=a.empty()?1:(a.back()+1);
            a.push_back(i);
        } a.clear();
        for (int i = n; i >= 1; --i) {
            while (!a.empty() && r[i][j]<=r[a.back()][j]) a.pop_back();
            d[i][j]=a.empty()?n:(a.back()-1);
            a.push_back(i);
        }
    }

    vector<vector<int>> ans(n+5, vector<int>(m+5, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans[1][r[i][j]]++;
            ans[i-u[i][j]+2][r[i][j]]--;
            ans[d[i][j]-i+2][r[i][j]]--;
            ans[d[i][j]-u[i][j]+3][r[i][j]]++;
        }
    }
    
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) ans[i][j]+=ans[i-1][j];
        for (int i = 1; i <= n; ++i) ans[i][j]+=ans[i-1][j];
    }

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 2; --j) {
            ans[i][j-1]+=ans[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ans[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}