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
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u); 
    }
    vector<int>color(n+1,-1);
    queue<pair<int,int>>pq;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            //bfs
            pq.push({1,i});
            color[i] = 1;
            while(!pq.empty()){
                int col = pq.front().first;
                int node = pq.front().second;
                pq.pop();
                for(auto it:adj[node]){
                    if(color[it]==-1){
                        color[it] = (col==1?2:1);
                        pq.push({color[it],it});
                    }
                    if(color[it]==col){
                        cout<<"IMPOSSIBLE"<<endl;
                        return;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastIO;
    solve();
    return 0;
}
