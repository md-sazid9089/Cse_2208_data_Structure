 #include<bits/stdc++.h>
 using namespace std;
 int rotated(vector<int>&a,int target){
 int low=0;
 int high=a.size()-1;
 while(low<=high){s
    int mid=(low+high)/2;
    if(a[mid]==target) return mid;
    else if(a[low]<=a[mid]){
        if(a[low]<=target && target<=a[mid]){
        high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    else {
        if(a[mid]<=target && target<<a[high]){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
 }
return -1;

 }

int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int l=4;
    int k=rotated(a,l);
    if(k==-1) cout<<"not found"<<endl;
    else cout<<"index is "<<k<<endl;
    return 0;

}
