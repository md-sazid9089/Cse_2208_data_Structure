#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);


    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start, target;
    cout << "Enter starting node and target node:" << endl;
    cin >> start >> target;

    vector<bool> visited(n+1, false);
    vector<int> level(n+1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    level[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto u : adj[cur]){
            if(!visited[u]){
                visited[u] = true;
                level[u] = level[cur] + 1;
                q.push(u);
            }
        }
    }

    if(level[target] != -1)
        cout << "Node " << target << " is at level " << level[target] << endl;
    else
        cout << "Node " << target << " is not reachable from " << start << endl;

    return 0;
}
