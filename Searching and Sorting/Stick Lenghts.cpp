#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
int n;
ll a[200005];
void solve() {
      cin>>n;
      for(int i=0;i<n;i++){
      	cin>>a[i];
      }
      sort(a,a+n);
      int mid = a[n/2];
      ll cst =0;
      for(int i=0;i<n;i++){
      	 cst += abs(mid-a[i]);
      }
      cout<<cst<<endl;
}
int main() {
    solve();
    return 0;
}
