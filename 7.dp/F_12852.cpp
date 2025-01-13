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

// 1시간 정도 걸림
// 순간의 최적해의 합이 글로벌 최적해이다. => 부분최적구조
// trace를 할 줄 아는가?

// 정답코드가 매우 간결함. 나누기 구현, min 사용법을 다시 볼 것.
// trace를 구현한게 신박함. 새로운 배열을 사용하여 pre를 하는 게 아닌 근본적인 방법을 알아볼것