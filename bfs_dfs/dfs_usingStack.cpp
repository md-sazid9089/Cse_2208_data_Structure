#include<bits/stdc++.h>
using namespace std;
void dfs(int v,int e){
vector<vector<int>>adj(v);
for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
cout<<"enter the starting vertex"<<endl;
int s;
cin>>s;
vector<bool>visit(v,false);
stack<int>st;
st.push(s);
while(!st.empty()){
    int cur=st.top();
    st.pop();

        cout<<cur<<endl;

        for(int u:adj[cur]){

                if(!visit[u]){
            visit[u]=true;
            st.push(u);

        }
    }
}

}
int main(){
int v,e;
cin>>v>>e;
dfs(v,e);
return 0;
}
