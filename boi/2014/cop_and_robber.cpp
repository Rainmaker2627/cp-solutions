#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

// modify the following functions
// you can define global variables and functions
int C=-1, cur=-1;
int dp[MAX_N][MAX_N][2], to[MAX_N][MAX_N];
vector<vector<int>> adj(MAX_N, vector<int>());
int start(int N, bool A[MAX_N][MAX_N]) {
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (A[u][v]) adj[u].push_back(v);
        }
    }
    
    queue<array<int, 3>> bfs;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        dp[i][i][0]=dp[i][i][1]=1;
        bfs.push({i,i,0});
        bfs.push({i,i,1});
        to[i][i]=i;
    }
    
    vector<vector<int>> cnt(N, vector<int>(N, 0));
    while(!bfs.empty()) {
        auto [r, c, t] = bfs.front(); bfs.pop();
        if (t==0) {
            for (auto i : adj[r]) {
                if (dp[i][c][1]) continue;
                cnt[i][c]++;
                if (cnt[i][c]==adj[i].size()) {
                    dp[i][c][1]=1;
                    bfs.push({i, c, 1});
                }
            }
        } else {
            adj[c].push_back(c);
            for (auto i : adj[c]) {
                if (dp[r][i][0]) continue;
                dp[r][i][0]=1;
                bfs.push({r, i, 0});
                to[r][i]=c;
            } adj[c].pop_back();
        }
    }

    for (int c = 0; c < N && C==-1; c++) {
        bool good=true;
        for (int r = 0; r < N && good; r++) {
            good&=dp[r][c][0];
        } if (good) C=c;
    } return cur=C;
}

int nextMove(int R) {
    cur=to[R][cur];
    return cur;
}

// don't modify the main function
int main() {
    int N;
    cin >> N;
    bool A[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int P = start(N,A);
    cout << P << endl;
    int R;
    cin >> R;
    while (true) {
        if (P == R) break;
        P = nextMove(R);
        cout << P << endl;
        if (P == R) break;
        cin >> R;
    }
}
