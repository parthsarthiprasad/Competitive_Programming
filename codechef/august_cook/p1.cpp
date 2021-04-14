#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n,k;
    cin>>n>>k;
    int ptr[n+1]={0};
    for(int i=1;i<=n;++i)cin>>ptr[i];
    int maxval = 0;
    for(int i=0;i<=n;i++) maxval = max(maxval,ptr[i]);
    if(maxval>k) return -1;
    for(int i=1;i<n;i++){ ptr[i]+=ptr[i-1];}
    int count = 0;
    for(int i=0;i<=n;++i){
        int j=i+1;
        while(j<=n && ptr[j]-ptr[i]<=k){j++;}
        count++;
        i=max(i,j-1);
    }
    return count;
    // sort(ptr,ptr+n , greater<int> ());
   
    // if(ptr[0]>k)return -1;
    // int count = 0;
    // int start = 0;
    // int end= n-1;
    // int sum = accumulate(ptr,ptr+n,0);
    // // for(int i=0;i<n;++i) cout<<ptr[i]<<" ";
    // // cout<<endl;
    // if(sum<=k) return 1;
    // sum=0;
    // while(start<=end){
    //     if(start<=end && sum+ptr[start]<=k){
    //         sum+=ptr[start];
    //         start++;
    //     }
    //     if(start<=end && sum+ptr[end]<=k){
    //         sum+=ptr[end];
    //         end--;
    //     }else{
    //         count++;
    //         sum=0;
    //     }
    // }
    // return count;

}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}