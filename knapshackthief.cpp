#include <iostream>
using namespace std;

int main() {
    // Items: rice, salt, saffron, sugar
    int weight[4]  = {12, 10, 8, 5};   // in kg
    int price[4]   = {840, 870, 2000, 500}; // total price
    double valuePerKg[4];

    // Knapsack capacity
    int capacity = 9;

    // Calculate value per kg
    for(int i=0; i<4; i++) {
        valuePerKg[i] = (double)price[i] / weight[i];
    }

    int thief = 1;
    while (true) {
        int remaining = capacity;
        double profit = 0;
        cout << "Thief " << thief << " carries: ";

        // Each thief will try to maximize profit
        while (remaining > 0) {
            int bestItem = -1;
            double bestValue = 0;

            // Find best available item
            for (int i=0; i<4; i++) {
                if (weight[i] > 0 && valuePerKg[i] > bestValue) {
                    bestValue = valuePerKg[i];
                    bestItem = i;
                }
            }

            if (bestItem == -1) break; // No items left

            // How much can thief take?
            int take = (weight[bestItem] >= remaining) ? remaining : weight[bestItem];

            // Update
            profit += take * valuePerKg[bestItem];
            weight[bestItem] -= take;
            remaining -= take;

            // Print item details
            if (bestItem == 0) cout << take << " kg Rice ";
            else if (bestItem == 1) cout << take << " kg Salt ";
            else if (bestItem == 2) cout << take << " kg Saffron ";
            else if (bestItem == 3) cout << take << " kg Sugar ";
        }

        cout << " | Profit = " << profit << " taka" << endl;

        // Stop if everything is taken
        bool allEmpty = true;
        for (int i=0; i<4; i++) {
            if (weight[i] > 0) allEmpty = false;
        }
        if (allEmpty) break;

        thief++;
    }

    return 0;
}