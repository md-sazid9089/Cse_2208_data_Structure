#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int>&b,int low,int high){
int index=b[low];
int i=low;
int j=high;
while(i<j){
    while(b[i]<=index && i<high){
        i++;
    }
    while(b[j]>index && j>low){
        j--;
    }
    if(i<j) swap(b[i],b[j]);
}
swap(b[low],b[j]);
return j;
}
void quick_sort(vector<int>&a,int low,int high){
if(low<high){
    int p=pivot(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
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
quick_sort(a,0,n-1);
for(int i=0;i<n;i++){
    cout<<a[i]<<"   ";
}
return 0;
}
