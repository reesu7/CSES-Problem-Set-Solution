#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input strings p and q
    string p, q;
    getline(cin, p);
    getline(cin, q);

    int m = p.size();
    int n = q.size();

    // Iterate over all possible starting indices in q where the first character of p matches
    for (int start = 0; start < n; start++) {
        if (q[start] != p[0]) continue; // first letter must match exactly
        
        int i = start; // pointer for q
        int j = 0;     // pointer for p
        int modifications = 0;

        // Try to match p as a subsequence of q starting at index 'start'
        while (i < n && j < m) {
            if (q[i] == p[j]) {
                // Characters match, advance in both strings
                i++;
                j++;
            } else {
                // Mismatch encountered, if not at p[0] and no modification used yet
                if (j > 0 && modifications == 0) {
                    modifications++;
                    // Treat the current q[i] as a modified match for p[j]
                    i++;
                    j++;
                } else {
                    // Either we are at the first character or already used modification
                    break;
                }
            }
        }

        // Check if we successfully matched all characters of p
        if (j == m) {
            cout << start << "\n";
            return 0;
        }
    }

    // If no valid subsequence is found, output -1
    cout << -1 << "\n";
    return 0;
}