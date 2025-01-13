#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,mx,ret;
int a[100004];

bool check(int mid){
    if(mx > mid) return false;
    int temp = mid;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(mid - a[i] < 0){
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    if(mid != temp) cnt++;
    
    return cnt <= m;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        r += a[i];
        mx = max(mx, a[i]);
    }
    while(l <= r){
        int m = (l+r) / 2;
        if(check(m)){
            r = m - 1;
            ret = m;
        }else{
            l = m + 1;
        }
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}