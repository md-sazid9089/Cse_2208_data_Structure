#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int src, dest;
    cin >> src >> dest;

    vector<int> dist(n, INF), parent(n);
    dist[src] = 0;
    for(int i = 0; i < n; i++) parent[i] = i;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    if(dist[dest] == INF) {
        cout << "No path\n";
    } else {
        vector<int> path;
        for(int v = dest; v != src; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for(int v : path) cout << v << " ";
        cout << "\nCost: " << dist[dest] << endl;
    }
}
