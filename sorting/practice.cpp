#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n, 1e9);
    int s, d;
    cin >> s >> d;

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edge = it.second;

            if(dis + edge < dist[adjNode]) {
                dist[adjNode] = dis + edge;
                pq.push({dist[adjNode], adjNode}); // ✅ Push updated node
            }
        }
    }

    if(dist[d] == 1e9)
        cout << "infinite error" << endl;
    else
        cout << dist[d] << endl;

    return 0;
}
