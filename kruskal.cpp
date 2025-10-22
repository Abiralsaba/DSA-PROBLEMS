#include <bits/stdc++.h>
using namespace std;

int f[105]; // union-find parent

int findp(int x){
    if(f[x]==x) return x;
    return f[x] = findp(f[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    int u[1005], v[1005], w[1005];
    int c = 0;

    for(int i = 0; i < m; i++){
        int a, b, weight;
        string s;
        cin >> a >> b >> weight >> s;
        if(s == "safe"){   // only safe edges
            u[c] = a;
            v[c] = b;
            w[c] = weight;
            c++;
        }
    }

    // sort edges by weight (ascending)
    for(int i = 0; i < c - 1; i++){
        for(int j = i + 1; j < c; j++){
            if(w[i] > w[j]){
                swap(w[i], w[j]);
                swap(u[i], u[j]);
                swap(v[i], v[j]);
            }
        }
    }

    // initialize union-find
    for(int i = 1; i <= n; i++) f[i] = i;

    int tot = 0;
    cout << "The selected edges:\n";

    for(int i = 0; i < c; i++){
        int a = findp(u[i]);
        int b = findp(v[i]);
        if(a != b){
            f[a] = b;
            cout << "(" << u[i] << "," << v[i] << "," << w[i] << ",safe)\n";
            tot += w[i];
        }
    }

    cout << "Total weight of the MST = " << tot << endl;
}
