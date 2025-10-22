#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // number of vertices
    int g[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j]; // adjacency matrix (0 if no edge)

    int key[n], parent[n];
    bool mst[n];

    for (int i = 0; i < n; i++) {
        key[i] = 1e9;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0; // start from vertex 0

    for (int c = 0; c < n - 1; c++) {
        int u = -1;

        // find vertex with minimum key not yet in MST
        for (int i = 0; i < n; i++)
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mst[u] = true;

        // update adjacent vertices
        for (int v = 0; v < n; v++)
            if (g[u][v] && !mst[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    int total = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << g[i][parent[i]] << endl;
        total += g[i][parent[i]];
    }
    cout << "Total weight: " << total << endl;
}

