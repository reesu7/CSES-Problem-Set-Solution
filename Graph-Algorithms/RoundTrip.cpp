#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
int dfs(int node, int parent, vector<int>& par, vector<vector<int>>& a, vector<bool>& visited, vector<int>& ans) {
    visited[node] = true;
    par[node] = parent;
    
    for (auto i : a[node]) {
        if (!visited[i]) {
            int loopStart = dfs(i, node, par, a, visited, ans);
            if (loopStart) return loopStart;
        } else if (i != parent) {
            par[i] = node;
            return i;
        }
    }
    return 0;
}
// find loop with a distance greater than 2
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> ans;
    int mn = INT_MAX;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        a[l].pb(r);
        a[r].pb(l);
        mn = min(mn,min(l,r));
    }
 
    for (int i = mn; i <= n; i++) {
        if (!visited[i]) {
            vector<int> par(n + 1, 0);
            ans.clear();
            int loopStart = dfs(i, -1, par, a, visited, ans);
            if (loopStart) {
            	ans.pb(loopStart);
                int node = par[loopStart];
                while (node != loopStart) {
                   ans.pb(node);
                   node = par[node];
                }
                ans.pb(loopStart);
                if (ans.size() > 3) {
                    cout << ans.size() << endl;
                    for (auto i : ans) cout << i << " ";
                    cout << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
 
 
 
int main() {
    fastIO;
    solve();
    return 0;
}
