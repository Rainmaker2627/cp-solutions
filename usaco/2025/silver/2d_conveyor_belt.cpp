#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> ok;
int bfs(int x, int y) {
    bool go=!ok[x][y]&&(ok[x-1][y]||ok[x][y-1]||ok[x+1][y]||ok[x][y+1]);
    if (!go) return 0;

    int a=0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [x, y]=q.front(); q.pop();
        if (ok[x][y]) continue;
        else ok[x][y]=true; a++;
        if (grid[x-1][y]=='D'||grid[x-1][y]=='.') q.push({x-1, y});
        if (grid[x][y-1]=='R'||grid[x][y-1]=='.') q.push({x, y-1});
        if (grid[x+1][y]=='U'||grid[x+1][y]=='.') q.push({x+1, y});
        if (grid[x][y+1]=='L'||grid[x][y+1]=='.') q.push({x, y+1});
    } return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> qs;
    grid.assign(n+2, vector<char>(n+2, '.'));
    ok.assign(n+2, vector<bool>(n+2, false));
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cin >> grid[a][b];
        qs.push_back({a, b});
    }

    vector<int> ans(q+1, 0);
    for (int i = 1; i <= n; i++) ok[i][0]=ok[n+1][i]=ok[n+1-i][n+1]=ok[0][n+1-i]=true;
    for (int i = 1; i <= n; i++) {
        if (grid[i][1]=='L' || grid[i][1]=='.') ans[q]+=bfs(i, 1);
        if (grid[n][i]=='D'|| grid[n][i]=='.') ans[q]+=bfs(n, i);
        if (grid[n+1-i][n]=='R' || grid[n+1-i][n]=='.') ans[q]+=bfs(n+1-i, n);
        if (grid[1][n+1-i]=='U' || grid[1][n+1-i]=='.') ans[q]+=bfs(1, n+1-i);
    }

    for (int i = q-1; i > 0; i--) {
        auto [x, y]=qs[i];
        grid[x][y]='.';
        ans[i]=ans[i+1]+bfs(x, y);
    }
    
    for (int i = 1; i <= q; i++) {
        cout << n*n-ans[i] << '\n';
    }

    return 0;
}