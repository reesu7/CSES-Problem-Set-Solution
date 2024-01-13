#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

void solve(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int dp[x+1];
    fill(dp,dp+x+1,0);
    dp[0]=1;
    for(int j=0;j<n;j++){
    	for(int i=1;i<=x;i++){
    		if(i-a[j]>=0)
    		dp[i] = (dp[i] + dp[i-a[j]])%mod;
    	}
    }
    cout<<dp[x]%mod<<endl;
}

int main(){
    solve();
    return 0;
}
