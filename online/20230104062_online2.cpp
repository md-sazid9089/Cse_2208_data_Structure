#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m1;
cin>>n>>m1;
vector<vector<int>>adj(n+1);;
for(int i=0;i<m1;i++){
int u,v;
cin>>u>>v;
adj[u].push_back(v);
adj[v].push_back(u);
}
vector<int>visited(n+1,0); queue<int>q;
vector<int>bfs;
int m;
cin>>m;
q.push(m);
visited[m]=1;
while(!q.empty()){
int node=q.front();
q.pop();
bfs.push_back(node);
for(auto it:adj[node]){
if(!visited[it]){
visited[it]=1;
q.push(it);
}
}
}
for(int i=bfs.size()-1;i>=0;i--)
    { cout<<bfs[i]<<" ";
}
cout<<endl;
}

