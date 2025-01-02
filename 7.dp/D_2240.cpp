#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n,m;
int a[1004],dp[1004][2][34];

int go(int time, int pos, int cnt){
    if(cnt < 0) return -INF;
    if(time == n) return 0;
    
    int &ret = dp[time][pos][cnt];
    if(~ret) return ret;
    return ret = max(go(time+1, pos^1, cnt-1), go(time+1, pos, cnt))+(pos == a[time]-1);
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];

    memset(dp,-1,sizeof(dp));
    cout << max(go(0,0,m), go(0,1,m-1));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}