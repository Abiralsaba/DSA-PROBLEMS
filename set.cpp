#include <bits/stdc++.h>
using namespace std;

int parent[105]; // parent[i] = parent of node i

// Find function with path compression
int findp(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

// Union function
void unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    if(a != b) parent[a] = b; // merge sets
}

int main() {
    int n; // number of elements
    cin >> n;

    // initialize each element as its own parent
    for(int i = 1; i <= n; i++) parent[i] = i;

    int q; // number of queries
    cin >> q;

    while(q--) {
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 1) { // union
            unite(a, b);
        } else if(type == 2) { // find
            if(findp(a) == findp(b)) cout << "Same set\n";
            else cout << "Different sets\n";
        }
    }
}
