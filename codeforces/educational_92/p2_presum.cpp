#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MXN = 2e5;
int n,k,z;
int ptr[MXN] , maxarr[MXN] ;
int  maxv = INT_MIN ; 
ll presum[MXN];
void process(){
    //preprocessing the input
    for(int i=0;i<n;i++) {
        cin>>ptr[i];
    }
        maxarr[0] = 0;
    for(int i=1;i<n;i++){
        maxv = max(maxv, ptr[i]+ ptr[i-1]);
        maxarr[i] = maxv;
    }
    presum[0]=ptr[0];
    for(int i=1;i<n;i++){
        presum[i] = ptr[i] + presum[i-1];
    }
}
ll solve(){
    
    cin>>n>>k>>z;
    maxv=INT_MIN;
    process();
    ll ans = INT_MIN;
    for(int i=0;i<=z && k-2*i>-1 ;i++){
        int index = k-2*i;
        ans = max(ans, presum[index] + (i)*(maxarr[index+1]));
    }
    return ans;
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9

15
19
150
56
*/
