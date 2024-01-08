#include<bits/stdc++.h>
using namespace std;
void solve() {
   int n;
   cin>>n;
   vector<ll>x(n);
   for(auto &i:x)cin>>i;
   sort(x.begin(),x.end());
   ll ans =0;
   for(int i=1;i<n;i++){
     if(x[i]!=x[i-1])ans++;
   }
   cout<<ans+1<<endl;
}
int main(){
  solve();
  return 0;
}
