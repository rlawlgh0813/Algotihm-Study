#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[34][34];

ll go(int h, int w){
    if(w == 0) return 1;
    if(dp[h][w]) return dp[h][w];

    if(h == 0) dp[h][w] = go(h+1, w-1);
    else dp[h][w] = go(h-1,w) + go(h+1, w-1);

    return dp[h][w];
}

void solve(){
    dp[0][1] = 1;
    while(true){
        int temp; cin >> temp;
        if(temp == 0) break;
        else cout << go(0,temp) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}

// 30분 정도 걸림
// 경우의 수는 더하기다!!
// 상태값을 저장해야겠다는 아이디어를 얻었어야함.