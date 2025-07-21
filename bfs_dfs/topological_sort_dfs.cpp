#include<bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis,
stack<int> &st){
vis[node]=1;
for(auto it:adj[node]){
int v=it.first;
if(!vis[v]) topoSort(v,adj,vis,st);
}
st.push(node);
}
int main(){
int n,m;
cin>>n>>m;
vector<pair<int,int>> adj[n];
for(int i=0;i<m;i++){
int u,v,w;
cin>>u>>v>>w;
adj[u].push_back({v,w});
}
vector<int> vis(n,0);
stack<int> st;
for(int i=0;i<n;i++){
if(!vis[i]) topoSort(i,adj,vis,st);
}
vector<int> dist(n,INT_MAX);
dist[0]=0;
while(!st.empty()){
int node=st.top();
st.pop();
for(auto it:adj[node]){
int v=it.first;
int wt=it.second;
if(dist[node]!=INT_MAX && dist[node]+wt<dist[v]){
dist[v]=dist[node]+wt;
}
}
}
for(int i=0;i<n;i++){
if(dist[i]==INT_MAX) cout<<"INF ";
else cout<<dist[i]<<" ";
}
}
