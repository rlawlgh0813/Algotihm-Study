#include <bits/stdc++.h>
using namespace std;
int n, m, ret = -1;
int a[54][54], dp[54][54], vis[54][54];
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};

int go(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 'H') return 0;
    if(vis[x][y]){ cout << -1; exit(0); }
    if(dp[x][y]) return dp[x][y];

    vis[x][y] = 1;
    int amt = (int)a[x][y] - '0';
    for(int i=0; i<4; i++){
        int nx = x + dx[i] * amt;
        int ny = y + dy[i] * amt;
        dp[x][y] = max(dp[x][y], go(nx,ny)+1);
    }
    
    vis[x][y] = 0;
    return dp[x][y];
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++) a[i][j] = s[j];
    }
    
    cout << go(0,0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();
    return 0;
}