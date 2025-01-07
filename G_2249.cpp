#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k;
int dp[10004], a[104];

void go(int val, int cnt){
    if(val <= 0) return;

    for(int i=0; i<n; i++){
        if(val - a[i] < 0 || dp[val-a[i]] < cnt+1) continue;

        dp[val-a[i]] = cnt+1;
        go(val - a[i], cnt+1);
    }
}

void solve(){
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<10001; i++) dp[i] = INF;

    go(k,0);
    cout << (dp[0]==INF ? -1 : dp[0]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}