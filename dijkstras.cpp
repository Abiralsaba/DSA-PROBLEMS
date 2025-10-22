#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges

    int g[105][105]; // adjacency matrix
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = INF; // initialize no edge

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;  // directed edge
        // for undirected graph: g[v][u] = w;
    }

    int src;
    cin >> src;

    int dist[105];
    bool visited[105] = {0};

    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[src] = 0;

    for(int i = 1; i <= n; i++){
        int u = -1;
        int mn = INF;

        // find unvisited node with smallest distance
        for(int j = 1; j <= n; j++){
            if(!visited[j] && dist[j] < mn){
                mn = dist[j];
                u = j;
            }
        }

        if(u == -1) break; // all reachable nodes processed
        visited[u] = true;

        // relax edges
        for(int v = 1; v <= n; v++){
            if(!visited[v] && g[u][v] != INF){
                if(dist[u] + g[u][v] < dist[v]){
                    dist[v] = dist[u] + g[u][v];
                }
            }
        }
    }

    // print distances
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) cout << "Node " << i << ": INF\n";
        else cout << "Node " << i << ": " << dist[i] << endl;
    }
}
