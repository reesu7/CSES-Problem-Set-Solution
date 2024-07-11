#include <bits/stdc++.h>
using namespace std;
long long dp[5001][5001];
long long f(int i,int n-1,vector<long long>&a){
     if(i>j) return 0;
     if(i==j) return a[i];
     if(dp[i][j]!=-1) return dp[i][j];
     long long c1 = a[i] + min(f(i+2,j),f(i+1,j-1));
     long long c2 = a[j] + min(f(i+1,j-1),f(i,j-2));
     return dp[i][j] = max(c1,c2);
}
int main(){
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(0,n-1,a);
    return 0;
}
