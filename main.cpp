#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// book allocation-----
bool isvalid( const vector<int>& arr,int n,int m,int mid){
    int student=1;int pages=0;
    for(int i=0;i<n;i++){
    if(arr[i]>mid) return false;
    if(pages+arr[i]<=mid){
        pages+=arr[i];
    }else{
        student++;
        pages=arr[i];
    }
    }
    if(student<=m) return true;
    else return false;
}
int bookallocation(vector<int>& arr,int m){
    if(m>arr.size()) return -1;
    if(arr.empty()) return -1;
    int n=arr.size();
    long long sum=0;int startval=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        startval=max(startval,arr[i]);
    }
    int minvalue=sum;
    int st=startval,end =sum;
    while(st<=end){
        int mid=st+((end-st)/2);
        if(isvalid(arr,n,m,mid)){
            minvalue=min(minvalue,mid);
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return minvalue;
}
bool isvalid2(const vector<int>& arr,int n,int c,int mid){
    int cow=1;int stall=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-stall>=mid){
            stall=arr[i];
            cow++;
        }
    }
    if(cow>=c) return true;
    else return false;
}
int agressivecows(vector<int>& arr,int c){
     sort(arr.begin(),arr.end());
    int n=arr.size();
    if(c>n) return -1;
    int ans=-1;
    int st=1;int end=arr[n-1]-arr[0];
    while(st<=end){
        int mid=st+((end-st)/2);
        if(isvalid2(arr,n,c,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return ans;
}
//dutch national flag algorithm---||---
void dnf(vector<int>& arr){
    int mid=0,low=0,high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return;
}
int main(){
    vector<int>arr={2,0,2,1,1,0,2,0,0};
    dnf(arr);
    return 0;
}