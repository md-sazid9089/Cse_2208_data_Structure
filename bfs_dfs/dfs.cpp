#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,vector<int>&res){
visited[node]=1;
res.push_back(node);

for(auto it:adj[node]){
    if(!visited[it]){
        dfs(it,visited,adj,res);
    }
}


}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n+1);;

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>visited(n+1,0);
vector<int>res;
int start=1;
dfs(start,visited,adj,res);


for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
cout<<endl;


}


