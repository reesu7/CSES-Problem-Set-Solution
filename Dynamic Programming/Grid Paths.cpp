#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int f(vector<vector<int>>&dp,vector<string>&a,int n,int x,int y){
	if(x>=n || y>=n || x<0 || y<0 || a[x][y]=='*'){
		return 0;
	}
	if(x==n-1 && y==n-1){
		return 1;
	}
	if(dp[x][y]!=-1)return dp[x][y];
	int right = f(dp,a,n,x+1,y);
	int left = f(dp,a,n,x,y+1);
	return dp[x][y] = (right+left)%mod;
}
void solve() {
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<f(dp,a,n,0,0)<<endl;
}
 
int main() {
    fastIO;
    solve();
    return 0;
}
