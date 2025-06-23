#include<bits/stdc++.h>
using namespace std;
void insertion_Sort(vector<int>&a){
    int n=a.size();
for(int j=1;j<n;j++){
    int key=a[j];
    int i=j-1;
while(i>=0 && a[i]>key){
    a[i+1]=a[i];
    i=i-1;
}
a[i+1]=key;
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
insertion_Sort(a);
for(int i=0;i<n;i++){
    cout<<a[i]<<"   ";
}
return 0;
}


