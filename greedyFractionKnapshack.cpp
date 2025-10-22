#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], value[100];
    float ratio[100];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> value[i];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> weight[i];

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Compute value/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sort by ratio using bubble sort (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    float totalValue = 0;
    int remaining = capacity;

    cout << "\nItems taken:\n";

    for (int i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            // take whole item
            totalValue += value[i];
            remaining -= weight[i];
            cout << "Take full item " << i + 1 << " (value=" << value[i] << ", weight=" << weight[i] << ")\n";
        }
         else {
            // take fraction
            float fraction = (float)remaining / weight[i];
            totalValue += value[i] * fraction;
            cout << "Take " << fraction * 100 << "% of item " << i + 1 
                 << " (value=" << value[i] << ", weight=" << weight[i] << ")\n";
            break; // bag full
        }
    }

    cout << "\nMaximum value in knapsack = " << totalValue << endl;

    return 0;
}
