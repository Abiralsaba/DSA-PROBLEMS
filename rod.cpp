#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // length of rod
    
    int price[105];
    for(int i = 1; i <= n; i++) cin >> price[i]; // price of rod length i
    
    int dp[105]; // dp[i] = max price for rod of length i
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        int mx = -1e9;
        for(int j = 1; j <= i; j++) {
            mx = max(mx, price[j] + dp[i - j]);
        }
        dp[i] = mx;
    }
    
    cout << dp[n] << endl;
}
