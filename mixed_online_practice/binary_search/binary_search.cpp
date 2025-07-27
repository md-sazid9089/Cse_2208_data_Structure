#include<bits/stdc++>
using namespace std;
int Binary_search(vector<int>&b,int e){
int low=0;
int high=b.size()-1;
while(low<=high){
    int mid=(low+high)/2;
    if(b[mid]==e) return mid;
    else if(b[mid]<e)low=mid+1;
    else high=mid-1;
}
return -1;
}
int main(){
int n;
cin>>n;
vector<int>a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
}
cout<<endl;
int element;
cin>>element;
int l
}
