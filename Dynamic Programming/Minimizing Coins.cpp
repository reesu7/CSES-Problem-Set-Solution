#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
const int INF = 1e6 + 7;
 
void solve(){
    int n;
    cin >> n;
    ll x;
    cin >> x;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int dp[x + 1];
    dp[0] = 0;
 
    for(int i = 1; i <= x; i++){
        dp[i] = INF;
        for(int j = 0; j < n; j++){
            if((i - a[j]) >= 0){
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
            }
        }
    }
 
    if(dp[x] == INF) {
        cout << "-1\n"; 
    } else {
        cout << dp[x] << endl;
    }
}
 
int main(){
    solve();
    return 0;
}
