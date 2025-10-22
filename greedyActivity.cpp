#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[100], finish[100];

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << "Enter finish times: ";
    for (int i = 0; i < n; i++) cin >> finish[i];

  
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                swap(finish[i], finish[j]);
                swap(start[i], start[j]);
            }
        }
    }

    cout << "\nSelected activities: ";

    int lastFinish = finish[0];
    cout << "(" << start[0] << "," << finish[0] << ") ";

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "(" << start[i] << "," << finish[i] << ") ";
            lastFinish = finish[i];
        }
    }

    cout << endl;
    return 0;
}
