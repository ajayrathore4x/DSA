#include<iostream>
#include<vector>
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