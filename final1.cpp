#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of projects:\n";
    cin >> n;

    int total_hours;
    cout << "Enter the total available working hours:\n";
    cin >> total_hours;

    vector<int> duration(n+1), payment(n+1);

    cout << "Enter the duration of each project:\n";
    for (int i = 1; i <= n; i++)
        cin >> duration[i];

    cout << "Enter the payments:\n";
    for (int i = 1; i <= n; i++)
        cin >> payment[i];

    // DP table
    vector<vector<int>> dp(n+1, vector<int>(total_hours+1, 0));

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int h = 0; h <= total_hours; h++) {
            if (duration[i] <= h)
                dp[i][h] = max(dp[i-1][h], payment[i] + dp[i-1][h - duration[i]]);
            else
                dp[i][h] = dp[i-1][h];
        }
    }

    int total_payment = dp[n][total_hours];

    // Reconstruct which projects were taken
    vector<bool> taken(n+1, false);
    int h = total_hours;
    for (int i = n; i >= 1; i--) {
        if (dp[i][h] != dp[i-1][h]) {
            taken[i] = true;
            h -= duration[i];
        }
    }

    cout << "Total Payment: " << total_payment << "\n";
    for (int i = 1; i <= n; i++) {
        cout << "Project " << i << " was ";
        if (taken[i])
            cout << "taken\n";
        else
            cout << "not taken\n";
    }

    return 0;
}