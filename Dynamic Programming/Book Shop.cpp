#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) { 
            if (j - h[i] >= 0) {
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]); 
            }
        }
    }
    cout << dp[x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
