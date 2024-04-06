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
int n,m;
vector<int>f1 = {-1,0,+1,0};
vector<int>f2 = {0,-1,0,+1};
vector<char>check = {'U','L','D','R'};
void solve() {
    cin>>n>>m;
    vector<string>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    vector<vector<char>> ls(n,vector<char>(m,'#'));
    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    int stx = -1;
    int sty = -1;
    int enx = -1;
    int eny = -1;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(a[i][j]=='A'){
    			stx = i;
    			sty = j;
    			break;
    		}
    	}
    	if(stx!=-1 && sty!=-1) break;
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(a[i][j]=='B'){
    			enx = i;
    			eny = j;
    			break;
    		}
    	}
    	if(enx!=-1 && eny!=-1) break;
    }
    pq.push({0,{stx,sty}});
    dis[stx][sty]  = 0;
    while(!pq.empty()){
    	int wei = pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
                 int x = node1 + f1[i];
                 int y = node2 + f2[i];
                 char ch = check[i];
                 if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#') continue;
                 if(wei+1 < dis[x][y]){
                     pq.push({wei+1,{x,y}});
                     dis[x][y] = wei+1;
                     ls[x][y] = ch;
                 }
       }
    }
    if(dis[enx][eny]==INT_MAX){
    	cout<<"NO"<<endl;
    	return;
    }
    int i = enx;
    int j = eny;
    string ans = "";
    while(i!=stx || j!=sty){
    	if(ls[i][j]=='U'){
    		i++;
    		ans += 'U';
    	}
    	else if(ls[i][j]=='R'){
    		j--;
    		ans += 'R';
    	}
    	else if(ls[i][j]=='L'){
    		j++;
    		ans += 'L';
    	}
    	else{
    		i--;
    		ans += 'D';
    	}
    }
    /*
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<ls[i][j];
    	}
    	cout<<endl;
    }
    */
    reverse(all(ans));
    cout<<"YES"<<endl;
    cout<<dis[enx][eny]<<endl;
    cout<<ans<<endl;
    
}
 
int main() {
    fastIO;
    //int t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}
