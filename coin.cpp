#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of coins
    cin >> n;
    
    int coins[105];
    for(int i = 0; i < n; i++) cin >> coins[i];
    
    int sum;
    cin >> sum;
    
    int dp[10005]; // dp[i] = min coins to make sum i
    int choice[10005]; // choice[i] = which coin was last used to reach sum i

    for(int i = 0; i <= sum; i++) {
        dp[i] = 1e9; // initialize to INF
        choice[i] = -1; // no coin chosen yet
    }
    
    dp[0] = 0; // 0 coins to make sum 0

    for(int i = 0; i < n; i++){ // for each coin
        for(int j = coins[i]; j <= sum; j++){ // update dp for sums >= coin
            if(dp[j - coins[i]] + 1 < dp[j]){
                dp[j] = dp[j - coins[i]] + 1;
                choice[j] = i; // store index of coin used
            }
        }
    }

    if(dp[sum] >= 1e9) {
        cout << "Impossible\n";
    } else {
        cout << "Minimum coins required: " << dp[sum] << endl;

        // Reconstruct which coins were used
        int s = sum;
        int used[105] = {0}; // count of each coin
        while(s > 0){
            int idx = choice[s];
            used[idx]++;
            s -= coins[idx];
        }

        cout << "Coins used:\n";
        for(int i = 0; i < n; i++){
            if(used[i] > 0)
                cout << coins[i] << " -> " << used[i] << " times\n";
        }
    }
}
