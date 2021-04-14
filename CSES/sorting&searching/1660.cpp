//subarray sums
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
     int count = 0;
     int start = 0, end  = 1;
     int sum = ptr[0];
    for(; end<=n; end++){
        while(sum>x && start < end-1){
            sum-=ptr[start++];
        }
        if(sum==x)count++;
        if(end<n) sum+=ptr[end];
    }
    cout<<count<<endl;
    //enhances mergesort might work again

}