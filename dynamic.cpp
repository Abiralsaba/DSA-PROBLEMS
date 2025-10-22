#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of projects:\n";
    cin >> n;

    int total_hours;
    cout << "Enter the total available working hours:\n";
    cin >> total_hours;

    int duration[100], payment[100]; 

    cout << "Enter the duration of each project:\n";
    for (int i = 1; i <= n; i++)
        cin >> duration[i];

    cout << "Enter the payments:\n";
    for (int i = 1; i <= n; i++)
        cin >> payment[i];

        // DP table
    int dp[105][105] = {0};

 // Filling DP table
    for (int i = 1; i <= n; i++) {
        for (int h = 0; h <= total_hours; h++) {
            if (duration[i] <= h)
                dp[i][h] = max(dp[i-1][h], payment[i] + dp[i-1][h - duration[i]]);
            else
                dp[i][h] = dp[i-1][h];
        }
    }

    int total_payment = dp[n][total_hours];

//taken not taken

  int h = total_hours;
cout << "Total Payment: " << total_payment << "\n";

for (int i = n; i >= 1; i--) {
    cout << "Project " << i << " was ";
    if (dp[i][h] != dp[i-1][h]) {
        cout << "taken\n";
        h -= duration[i];
    } else {
        cout << "not taken\n";
    }
}
}
