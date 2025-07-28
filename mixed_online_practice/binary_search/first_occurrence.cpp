#include<bits/stdc++.h>
using namespace std;
int firstOccurance(vector<int>&a,int n,int x){
int low=0;
int high=n-1;
int result=-1;
while(low<=high){
    int mid=(low+high)/2;
    if(a[mid]==x){
        result=mid;
        high=mid-1;
    }
    else if(a[mid]<x){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return result;
}
int main(){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
int x;
cin>>x;
int l=firstOccurance(a,n,x);
cout<<l<<endl;
}
