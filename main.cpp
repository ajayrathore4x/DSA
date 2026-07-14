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
    int largestval=INT_MIN;int smallestval=INT_MAX;
    for(int i=0;i<n;i++){
        largestval=max(largestval,arr[i]);
        smallestval=min(smallestval,arr[i]);
    }
    int ans=-1;
    int st=1;int end=largestval-smallestval;
    while(st<=end){
        int mid=st+((end-st)/2);
        if(isvalid2(arr,n,c,mid)){
            ans=max(ans,mid);
            st=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return ans;
}
int main(){
    vector<int>arr={1,2,8,4,9};
    cout<<agressivecows(arr,2)<<endl;
    return 0;
}