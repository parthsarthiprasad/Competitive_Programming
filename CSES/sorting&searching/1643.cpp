//classic kadane's algorithm
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long 
ll solve(){
    int n;
    cin>>n;
    ll temp;
    ll maxsum = -1e10;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum+=temp;
        maxsum =max(maxsum,sum);
        sum = max(sum, 0LL);
    }
    return maxsum;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}
/*
8
-1 3 -2 5 3 -5 2 2
*/