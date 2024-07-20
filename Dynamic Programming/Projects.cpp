/*
Explanation - 
Question is asked about selecting projects so that we can maximize our profit . For a minute 
you may remember activity selection problem but this question doesn't work that 
way as you have to maximize the profit not days (so you can't be greedy as you have no idea how much profit others can give.)
Thinking of other way that is dp.
Just try out all combination and try to pick - not pick projects.
Look for maximum profit out there
Also if you have choosen a project you have to wait to finish it so after finishing you can only
pick project whose starting time is more than current finishing time
to optimize the selection of project whose starting time is greater than finishing 
time i used ordered set ( pushed starting time in ordered set) and used order_of_key(no of elements smaller than finishing time)
to find index of next project
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

pbds os;
ll f(vector<ll>& dp, vector<pair<pair<ll, ll>, ll>>& a, int i,int n) {
    if (i == n) {
        return 0;
    }
    if (dp[i] != -1) return dp[i];
 
    ll mxi = a[i].second;
    ll end = a[i].first.second + 1;
    ll less = os.order_of_key(end);
    ll idx = less;
    if (idx<n){
        mxi = max(mxi, a[i].second + f(dp, a, idx,n));
    }
    mxi = max(mxi, f(dp, a, i + 1,n));
    return dp[i] = mxi;
}
void solve() {
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
        os.insert(a[i].first.first);
    }
    vector<ll> dp(n, -1);
    ll result = f(dp, a, 0,n);
    cout << result << endl; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
