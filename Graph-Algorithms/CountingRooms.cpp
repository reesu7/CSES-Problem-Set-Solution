#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
const int mod = 1000000007;
int n,m;
char adj[1000][1000];
void dfs(vector<vector<int>>&vis,int i,int j){
	if(i<0 || j<0 || i>=n || j>=m || adj[i][j]=='#' || vis[i][j]){
		return;
	}
	vis[i][j] = true;
	dfs(vis,i+1,j);
	dfs(vis,i-1,j);
	dfs(vis,i,j+1);
	dfs(vis,i,j-1);
}
void solve() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>adj[i][j];
		}
	}
    vector<vector<int>>vis(n,vector<int>(m,false));
    int cnt =0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(adj[i][j]=='.' && vis[i][j]==false){
    			dfs(vis,i,j);
    			cnt++;
    		}
    	}
    }
    cout<<cnt<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
