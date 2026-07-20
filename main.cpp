#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<cmath>
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
void mergesortedarray(vector<int>& nums1,int m,vector<int>& nums2,int n){
    int end=(m+n)-1;
    int e1=m-1,e2=n-1;
    while(e1>=0&&e2>=0){
        if(nums1[e1]<=nums2[e2]){
            nums1[end]=nums2[e2];
            end--;
            e2--;
        }else{
            nums1[end]=nums1[e1];
            end--;e1--;
        }
    }
    while (e2 >= 0) {
    nums1[end] = nums2[e2];
    end--;
    e2--;
}
    for (int i=0;i<=(m+n)-1;i++){
        cout<<nums1[i]<<" ";
    }
    return;
}
// reverse string ---||-----
void reversestring(string& s){
int i=0;int j=s.length()-1;
while(i<j){
    swap(s[i],s[j]);
    i++;j--;
}
return;
}
//is a valid palindrome-----||-----
bool isvalidpalindrome(const string& s){
    if(s.empty()) return true;
   int i=0,j=s.size()-1;
   while(i<j){
    if(s[i]!=s[j]) return false;
    i++;j--;
   }
   return true;
}
bool validpalindrome2(const string& s){
    string x="";
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        x+=s[i];
    }
    else if(s[i]>='A'&&s[i]<='Z'){
        x+=(s[i]-'A')+'a';
    }
    else if(s[i]>='a'&&s[i]<='z'){
        x+=s[i];
    }
}
 int i=0,j=x.size()-1;
 while(i<j){
    if(x[i]!=x[j]) return false;
    i++;j--;
 }
 return true;
}
bool isvalidpalindrome2(const string& s){
    if(s.empty()) return true;
    int i=0,j=s.size()-1;
    while(i<=j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
             j--;
            continue;
        }

        if(tolower(s[i])!=tolower(s[j])) return false;
        i++;j--;
    }
    return true;
}
string removeoccurance(string s,string part){
    while(1){
        size_t pos=s.find(part);
        if(pos==string::npos) return s;
            s.erase(pos,part.length());
    }
}
string reversewords(string& s){
    reverse(s.begin(),s.end());
    return s;
}
int compressstring(vector<char>& chars){
    int idx=0;
    for(int i=0;i<chars.size();i++){
        char ch=chars[i];
        int count=0;

        while(i<chars.size()&&chars[i]==ch){
            count++;i++;
        }
        if(count==1){
            chars[idx++]=ch;
        }
        else{
            chars[idx++]=ch;
            string str=to_string(count);
            for(char dig:str){
                chars[idx++]=dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}
int primecount(int n){
    vector<bool>isprime(n+1,true);
        isprime[0] = isprime[1] = false;
    int count=0;
    for(int i=2;i<n;i++){
        if(isprime[i]){
            count++;
        if ((long long)i * i < n) {
        for(int j=i*i;j<n;j=j+i){
            isprime[j]=false;
        }
       }
     }
    }
    return count;
}
bool isarmstrong(int n){
    int x=0;
    int original=n;
    while(n>0){
        int rem=n%10;
        x+=rem*rem*rem;
        n=n/10;
    }
    return x==original;
}
int gcdofaddneven(int n){
    return n;
}
int reversenums(int n){
    int ans=0;
    while(n!=0){
        int rem=n%10;
        if(ans>INT_MAX/10||ans<INT_MIN/10){
            return 0;
        }
        ans=(ans*10)+rem;
        n=n/10;
    }
    return ans;
}
bool ispalindrome(int n){
    if(n<0) return false;
    int original=n;
    int rev=0;
        while(n!=0){
        int rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
    }
    if(rev==original)return true;
    else return false;
}
pair<int,int> linearsearch2darray( int arr[][3],int n,int target){
    for(int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            if(arr[i][j]==target) return {i,j};
        }
    }
    return {-1,-1};
}
vector<int> removeduplicate(vector<int>& arr){
    int idx=0;
    for(int i=0;i<arr.size();i++){
        bool found=false;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]) {
                found=true;
                break;
            }
        }if(!found){ arr[idx]=arr[i];idx++;}
    }
    arr.resize(idx);
    return arr;
}
int removeduplicate2(vector<int>& arr){
    if (arr.empty()) return 0;
int idx=1;
for(int i=1;i<arr.size();i++){
if(arr[i]!=arr[idx-1]){     
        arr[idx]=arr[i];
         idx++;
    }
}
arr.resize(idx);
return idx;
}
int main(){
    vector<int>arr={1,2,2,3,4,5,5,6};
   cout<<removeduplicate2(arr)<<endl;
    return 0;
}