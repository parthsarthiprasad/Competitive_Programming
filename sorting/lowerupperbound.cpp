#include<bits/stdc++.h>
using namespace std;
int first(int arr[],int low, int high, int x,int n){
    if(hish>=low){
        int mid = low + (high-low)/2;
        if((mid==0) || (x > arr[mid-1] && arr[mid]==x)) return mid;
        else if(x>arr[mid]){
            return first(arr,mid+1,high,x,n);
        }else{
            rturn first(arr,low,mid-1,x,n);
        }
    }
    return -1;
}
int last(int arr[],int low,int high,int x,int n){
    if(high>=low){
        int mid = low + (high - low)/2;
        if((mid == n-1) || (x<arr[mid+1] && arr[mid]==x)) return mid;
        else if(x<arr[mid]) return last(arr,low,mid-1,x,n)'
        else return last(arr,mid+1,high,x,n);
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i)cin>>ptr[i];
    cout<<firestoccourance(ptr,0,n-1,x,n);
    cout<<lastoccourance(ptr,0,n-1,x,n);
    return 0;
}