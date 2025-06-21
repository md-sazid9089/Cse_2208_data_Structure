#include<bits/stdc++.h>
using namespace std;
int mySqrt(vector<int>&a,int x){
long long low=0;
long long high=x;
int ans=0;
while(low<=high){
    int mid=(low+high)/2;
    if(mid*mid==x) return mid;
    else if(mid*mid >x) high=mid-1;
    else{
        low=mid+1;
        ans=mid;
    }
}
return ans;
}
int main(){
int n;
cin>>n;
cout<<endl;
vector<int>a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
}
int x=4;
int l=mySqrt(a,x);
if(l==0) cout<<"not found"<<endl;
else cout<<"the square is  "<<l<<endl;
return 0;
}
