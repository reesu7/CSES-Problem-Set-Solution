#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
 
class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) 
            parent[i] = i;
    }
 
    int findUpar(int node) {
        if (node == parent[node]) 
            return node;
        return parent[node] = findUpar(parent[node]);
    }
 
    bool unionBysize(int u, int v) {
        int ulp = findUpar(u);
        int vlp = findUpar(v);
        if (ulp == vlp) 
            return false;
        if (size[ulp] < size[vlp]) 
            swap(ulp, vlp);
        parent[vlp] = ulp;
        size[ulp] += size[vlp];
        return true;
    }
 
    bool check() {
        set<int> components;
        for (int i = 1; i < parent.size(); i++) {
            components.insert(findUpar(i));
        }
        return components.size() == 1;
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> edges;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (auto &edge : edges) {
        if (dsu.unionBysize(edge.second.first, edge.second.second)) {
            ans += edge.first;
        }
    }
    if (!dsu.check()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans << endl;
}
 
int main() {
    fastio();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
