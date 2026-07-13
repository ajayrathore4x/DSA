#include<iostream>
#include<vector>
using namespace std;

//check whether array with single elements is sorted or not ? ---||---
bool issorted(vector<int>& arr){
    if(arr.size()<2) return true;
    if(arr[0]<arr[1]){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
 }else{
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]<arr[i+1]){
            return false;
        }
    }
 }
 return true;
}
int main(){
 vector<int>arr={5,4,3,2,1};
 cout<<issorted(arr)<<endl;
    return 0;
}