#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
}
int s;
cin>>s;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,s});
vector<int>dist(n,1e9);
dist[s]=0;
while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto it:adj[node]){
        int adjnode=it.first;
        int adjEdge=it.second;
        if(dis+adjEdge<dist[adjnode]){
            dist[adjnode]=dis+adjEdge;
            pq.push({dist[adjnode],adjnode});
        }
    }
}
for(int i=0;i<n;i++){
    if(dist[i]==1e9) cout<<"error"<<endl;
    else cout<<dist[i]<<endl;
}
}
