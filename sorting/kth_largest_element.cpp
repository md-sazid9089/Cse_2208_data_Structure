#include<bits/stdc++.h>
using namespace std;
void merges(vector<int>&b,int low,int mid,int high){
vector<int>temp;
int left=low;
int right=mid+1;
while(left<=mid && right<=high){
    if(b[left]<=b[right]){
        temp.push_back(b[left]);
        left++;
    }
    else{
        temp.push_back(b[right]);
        right++;
    }
}
while(left<=mid){
    temp.push_back(b[left]);
    left++;
}
while(right<=high){
    temp.push_back(b[right]);
    right++;
}
for(int i=low;i<=high;i++){
    b[i]=temp[i-low];
}
}
void merge_sort(vector<int>&a,int low,int high){
if(low<high){
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merges(a,low,mid,high);
}

}
int main(){
int n;
cin>>n;
cout<<endl;
vector<int>a(n);
for(int i=0;i<n;i++){
   cin>>a[i];
}
int k;
cin>>k;
cout<<endl;
merge_sort(a,0,n-1);
int index=n-k;
cout<<a[index]<<endl;
}

