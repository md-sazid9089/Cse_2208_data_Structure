#include<bits/stdc++.h>
using namespace std;

void dfs(int v, int e){
    vector<vector<int>> adj(v);


    for(int i=0; i<e; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "Enter the starting vertex" << endl;
    int start;
    cin >> start;

    vector<bool> visit(v, false);
    stack<int> st;

    st.push(start);
    visit[start] = true;

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        bool isLeaf = true;

        for(int u : adj[cur]){
            if(!visit[u]){
                visit[u] = true;
                st.push(u);
                isLeaf = false;
            }
        }

        if(isLeaf){
            cout << "Leaf node: " << cur << endl;
        }
    }
}

int main(){
    int v,e;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> v >> e;
    dfs(v,e);
    return 0;
}
