#include<bits/stdc++.h>
using namespace std;
int swapCount=0;
int part(vector<int> &a, int st, int ed) {
    int idx = st - 1;
    int pivot = a[ed];

    for (int j = st; j < ed; j++) {
        if (a[j] <= pivot) {
            idx++;
            swap(a[j], a[idx]);
            swapCount++;
        }
    }
    idx++;
    swap(a[ed], a[idx]);
    swapCount++;
    return idx;
}
void quickSort(vector<int>&a,int st,int ed){
if(st<ed){
    int pivot=part(a,st,ed);
    quickSort(a,st,pivot-1);
    quickSort(a,pivot+1,ed);
}
}
int main(){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
quickSort(a,0,n-1);
cout<<swapCount<<endl;
return 0;
}
