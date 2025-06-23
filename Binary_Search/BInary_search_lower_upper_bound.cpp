#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>&a,int n,int x){
int low=0;
int high=n;
while(low<high){
    int mid=(low+high)/2;
    if(a[mid]>=x) high=mid-1;
    else low=mid+1;
}
if(low<n && a[low]<x)low++;
return low;
}
int uperBound(vector<int>&a,int n,int x){
int low=0;
int high=n;
while(low<high){
    int mid=(low+high)/2;
    if(a[mid]>x) high=mid;
    else low=mid+1;
}
if(low<n && a[low]<x)low++;
return low;
}
int main(){
vector<int>a;
int n;
cin>>n;
cout<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
}
int element=3;
int l=uperBound(a,n,element);
if(l==n) cout<<"not found"<<endl;
else cout<<l<<endl;
}
