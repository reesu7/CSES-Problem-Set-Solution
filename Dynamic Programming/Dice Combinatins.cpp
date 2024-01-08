//TABULATION SOLUTION - BOTTOM UP APPROACH
#include<bits/stdc++.h>

using namespace std;



 
void solve() {
  ll n;
  cin>>n;
 
  vector<ll>dp(n+1,0);
  dp[0] = 1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
        if(i>=j)
        dp[i] = (dp[i] + dp[i-j])%MOD;
    }
  }
  cout<<dp[n]<<endl;
}
 
 
int main() {

    solve();
    return 0;
}
