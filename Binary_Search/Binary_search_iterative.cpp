#include<bits/stdc++.h>
using namespace std;
int Binary_search(vector<int>&b,int e){
    int low=0;
    int high=b.size()-1;
    while(low<=high){
int mid=(low+high)/2;
if(b[mid]==e) return mid;
else if (e<b[mid]) high=mid-1;
else low=mid+1;
    }
    return -1;
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
int element=10;
int l=Binary_search(a,element);
if(l==-1) cout<<"not found"<<endl;
else cout<<l<<endl;
}
