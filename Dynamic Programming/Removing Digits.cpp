#include <bits/stdc++.h>
using namespace std;
void solve() {
    string n;
    cin >> n;
    int target = stoi(n);
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        string p = to_string(i);
        for (int j = 0; j < p.size(); j++) {
            if (i - (p[j] - '0') >= 0) {
                dp[i] = min(dp[i], dp[i - (p[j] - '0')] + 1);
            }
        }
    }
    cout << dp[target];
}

int main() {
    fastIO;
    solve();

    return 0;
}
