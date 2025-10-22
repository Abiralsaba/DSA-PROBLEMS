#include <iostream>
#include <climits>
using namespace std;

// Function to find maximum crossing sum
int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

// Recursive function to find maximum subarray sum
int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    int left = maxSubArraySum(arr, l, m);
    int right = maxSubArraySum(arr, m + 1, r);
    int cross = maxCrossingSum(arr, l, m, r);

    return max(max(left, right), cross);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max_sum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum = " << max_sum << endl;

    return 0;
}
