#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int n;
int dp[INF+4], idx[INF+4];

void solve(){
    idx[1] = -1;
    for(int i=2; i<=INF; i++){
        dp[i] = dp[i-1] + 1;
        idx[i] = i-1;

        if(i % 3 == 0 && dp[i] > dp[i/3]){
            dp[i] = dp[i/3] + 1;
            idx[i] = i / 3;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2]){
            dp[i] = dp[i/2] + 1;
            idx[i] = i / 2;
        }
    }
    
    cin >> n;
    cout << dp[n] << '\n';
    while(n != -1){
        cout << n << " ";
        n = idx[n];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}