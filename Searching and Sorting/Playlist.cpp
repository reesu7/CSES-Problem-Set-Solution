#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n;
    cin>>n;
    ll k[n];
    for(int i=0;i<n;i++)cin>>k[i];
    map<int,int>mp;
    int mx = 1;
    int r = 0;
    int l = 0;
    for(r;r<n;r++){
    	if(mp.find(k[r])!=mp.end()){
    		mx = max(mx,r-l);
    		l = max(mp[k[r]]+1,l);
    	}
    	mp[k[r]] = r;
    }
    mx = max(mx,r-l);
    cout<<mx<<endl;
}

int main() {
    solve();
    return 0;
}
