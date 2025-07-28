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
        adj[v].push_back({u, w}); // if undirected
    }

    int s;
    cin >> s;

    vector<int> dist(n, INF);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Unreachable nodes: ";
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) cout << "None";
    cout << endl;
    return 0;
}
