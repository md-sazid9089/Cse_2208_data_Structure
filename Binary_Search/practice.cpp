#include<bits/stdc++.h>
using namespace std;
int sqrt(vector<int>&a,int x){
int low=0;
int high=a.size()-1;
while(low<=high){
    int mid=(low+high)/2;
    if(mid*mid ==x) return mid;
    else if(mid*mid<x) low=mid+1;
    else high=mid+1;
}
return -1;
}
int main(){
int n;
cin>>n;
vector<int>a;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    a.push_back(x);
}
int x=16;
int l=sqrt(a,x);
if(l==-1)cout<<"not found"<<endl;
else cout<<l<<endl;
}
