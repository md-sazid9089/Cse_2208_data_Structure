#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<bool> &visit){
    queue<int> q;
    visit[start] = true;
    q.push(start);

    cout << "Starting BFS from node: " << start << endl;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << "Visited node: " << curr << endl;

        for(int u : adj[curr]){
            if(!visit[u]){
                visit[u] = true;
                q.push(u);
                cout << "  --> Node " << u << " is now visited and pushed to queue." << endl;
            }
        }
    }
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
    int components = 0;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            cout << "Component " << components + 1 << " found starting at node " << i << endl;
            bfs(i, adj, visit);
            components++;
        }
    }

    cout << "Number of connected components: " << components << endl;

    return 0;
}
