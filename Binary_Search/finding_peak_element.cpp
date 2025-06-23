#include<bits/stdc++.h>
using namespace std;
int find_peak(vector<int>&num){
int low=0;
int high=num.size()-1;
int peak=-1;
while(low<=high){
    int mid=(low+high)/2;
      bool leftOk = (mid == 0 || num[mid - 1] <= num[mid]);
        bool rightOk = (mid == num.size() - 1 || num[mid + 1] <= num[mid]);

   if(leftOk && rightOk)
   {
       peak=mid;
       break;
   }
  else if(mid>0 && num[mid-1]>num[mid]){
    high=mid-1;
   }
   else {
    low=mid+1;
   }
}
return peak;
}
int main(){
int n;
cin>>n;
cout<<endl;
vector<int>a;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    a.push_back(x);
}
int x=16;
int l=find_peak(a);
if(l==-1)cout<<"not found"<<endl;
else cout<<l<<endl;
}
