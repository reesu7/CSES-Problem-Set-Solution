#include <iostream>
#include <set>

using namespace std;

#define ll long long
const int mod = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> mp;

    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        mp.insert(val);
    }

    for (int i = 0; i < m; i++) {
        cin >> val;
        auto it = mp.lower_bound(val);

        if (mp.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        if (*it == val) {
            cout << *it << endl;
            mp.erase(it);
        } else if (it != mp.begin()) {
            --it;
            if (*it < val) {
                cout << *it << endl;
                mp.erase(it);
            } else {
                cout << -1 << endl;
            }
        } else if (it == mp.begin()) {
            if (*it < val) {
                cout << *it << endl;
                mp.erase(it);
            } else {
                cout << -1 << endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
