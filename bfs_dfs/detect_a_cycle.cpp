#include<bits/stdc++.h>
using namespace std;
bool bfs_cycle(int start, vector<vector<int>> &adj, vector<bool> &visit){
    queue<pair<int, int>> q;
    visit[start] = true;
    q.push({start, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int u : adj[node]){
            if(!visit[u]){
                visit[u] = true;
                q.push({u, node});
            }

                       else if(u != parent){
                return true;
            }
        }
    }

    return false;
}

int main(){
    cout << "Enter number of vertices and edges: ";
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    cout << "Enter edges (u v):" << endl;
    for(int i=0;i<e;i++){
        int u, v1;
        cin >> u >> v1;
        adj[u].push_back(v1);
        adj[v1].push_back(u);
    }

    vector<bool> visit(v, false);
    bool cycle_found = false;
for(int i=0;i<v;i++){
        if(!visit[i]){
            if(bfs_cycle(i, adj, visit)){
                cycle_found = true;
                break;
            }
        }
    }

    if(cycle_found)
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;

    return 0;
}
