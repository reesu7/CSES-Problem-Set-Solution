#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF LLONG_MAX
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
void dfs(vector<int>&vis,vector<vector<int>>&adj,int node){
	vis[node] = 1;
	for(auto i:adj[node]){
		if(!vis[i]) dfs(vis,adj,i);
	}
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    int u,v;
    for(int i=0;i<m;i++){
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    vector<int>vis(n+1,0);
    int cnt = 0;
    int prev = -1;
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		cnt++;
    		dfs(vis,adj,i);
    		if(prev!=-1){
    			ans.pb({prev,i});
    		}
    		else{
    			prev = i;
    		}
    	}
    }
    cout<<cnt-1<<endl;
    for(auto i:ans){
    	cout<<i.first<<" "<<i.second<<endl;
    }
}
 
int main() {
    fastIO;
    solve();
    return 0;
}
