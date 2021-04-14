#include<bits/stdc++.h>
using namespace std;
bool valid(int k,int ptr[],int n,int m){
    int num=0;
    for(int i=0;i<n;i++){
        num+= (ptr[i]/k);
        if(ptr[i]%k) num++;
    }
    return (num<=m);
}
int bsearch(int ptr[],int n,int m){
    int minsize = 1;
    int maxsize = *max_element(ptr,ptr+n);
    int sz = minsize;
    while(minsize<=maxsize){
        int mid = minsize + (maxsize - minsize)/2;
        if(valid(mid,ptr,n,m)){
            sz=mid;
            maxsize = mid-1;
        }else{
            minsize=mid+1;
        }
    }
    return sz;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    int ans = bsearch(ptr,n,m);
    cout<<ans<<endl;
    return 0; 
}