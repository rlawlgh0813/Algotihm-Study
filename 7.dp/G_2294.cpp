#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k;
int dp[10004], a[104];

void solve(){
    cin >> n >> k;
    fill(dp,dp+10004,INF);
    dp[0] = 0;

    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        for(int j=temp; j<=k; j++) dp[j] = min(dp[j], dp[j-temp]+1);
    }
    cout << (dp[k]==INF ? -1 : dp[k]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}


// n가지 동전을 무한번(횟수 제한 없이) 사용 가능하다 -> dp를 아래에서부터..
// n가지를 1개씩.. -> dp를 오른쪽부터