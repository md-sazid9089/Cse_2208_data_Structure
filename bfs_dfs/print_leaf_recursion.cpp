#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans){
visited[node]=1;
bool isLeaf=true;

for(auto it:adj[node]){
    if(!visited[it]){
        isLeaf=false;
        dfs(it,adj,visited,ans);
    }
}

if(isLeaf) ans.push_back(node);
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n+1);
vector<int>ans;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>visited(n+1,0);s
for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs(i,adj,visited,ans);
    }
}

for(auto x:ans){
    cout<<x<<" ";
}
cout<<endl;

}
