#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int find(int p[], int x) {
    if (p[x] == x) return x;
    return p[x] = find(p, p[x]); // path compression
}

void unite(int p[], int r[], int a, int b) {
    a = find(p, a);
    b = find(p, b);
    if (a != b) {
        if (r[a] < r[b]) p[a] = b;
        else if (r[a] > r[b]) p[b] = a;
        else { p[b] = a; r[a]++; }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    Edge edges[e];

    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges, edges + e, [](Edge a, Edge b) { return a.w < b.w; });

    int p[n], r[n];
    for (int i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    int total = 0;
    cout << "Edges in MST:\n";
    int cnt = 0;

    for (int i = 0; i < e && cnt < n - 1; i++) {
        int a = find(p, edges[i].u);
        int b = find(p, edges[i].v);

        if (a != b) {
            unite(p, r, a, b);
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            total += edges[i].w;
            cnt++;
        }
    }

    cout << "Total weight: " << total << endl;
}
