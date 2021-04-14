//subarray sums
#include<bits/stdc++.h>
using namespace std;
bool valid(int x,int ptr[],int k,int n){
    int count = 0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(ptr[i]>x) return false;
        if(sum+ptr[i]>x){
            count++;
            sum=ptr[i];
        }else{
            sum+=ptr[i];
        }
    }
    return (count<=k);
}
int binarysearch(long low,long high,int val, int ptr[] , int n){
    long start = low,end = high;
    long answer;
    while(start<=end){
        long mid = start + (end-start)/2;
        if(valid(mid,ptr,val,n)){
            answer = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return answer;
    // int mid = low + (high - low)/2;
    // if(low==high) return high;
    // if(valid(mid,ptr,val,n)){
    //     return binarysearch(low,mid,val,ptr,n);
    // }else{
    //     return binarysearch(mid+1,high,val,ptr,n);
    // }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    long long sum=0;
    accumulate(ptr, ptr+n,sum);
    cout<< binarysearch(1,sum,x, ptr,n);

}